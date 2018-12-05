#include "Thingy.h"
#include <QDebug>

Thingy::Thingy(){
}

Thingy::Thingy(QBluetoothAddress ad){
   address = ad;
}

Thingy::~Thingy(){

}

void Thingy::setAddress(QBluetoothAddress ad){
   address = ad;
}

QBluetoothAddress Thingy::getAddress(){
   return address;
}

void Thingy::setInfo(QBluetoothDeviceInfo i){
   info = i;
   controller = QLowEnergyController::createCentral(info);
   connect(controller, SIGNAL(connected()), this, SLOT(connectedToDevice()));
   connect(controller, SIGNAL(discoveryFinished()), this, SLOT(serviceDiscovered()));
   controller->setRemoteAddressType(QLowEnergyController::RandomAddress);
   controller->connectToDevice();
}

QBluetoothDeviceInfo Thingy::getInfo(){
   return info;
}

void Thingy::setController(QLowEnergyController* ctrl){
   controller = ctrl;
}

QLowEnergyController* Thingy::getController(){
   return controller;
}

void Thingy::addService(QLowEnergyService* serv){
   
}

void Thingy::changeColor(Qt::GlobalColor color){
   switch(color){
   case Qt::red:{    
        service->writeCharacteristic(led,QByteArray::fromHex("01ff0000"));
	break;
   }
   case Qt::blue:{	
        service->writeCharacteristic(led,QByteArray::fromHex("010000ff"));
	break;
   
   }
   case Qt::green:{
	service->writeCharacteristic(led,QByteArray::fromHex("0100ff00"));
	break;
   }

   default:{
        service->writeCharacteristic(led,QByteArray::fromHex("01ffffff"));
   	break;
   }
   }
}

void Thingy::switchOffLed(){
   service->writeCharacteristic(led,QByteArray::fromHex("00"));
}

void Thingy::buttonChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue){
   emit buttonStateChanged(characteristic, newValue, getAddress());
}
void Thingy::motionChanged(const QLowEnergyCharacteristic &characteristic,
                           const QByteArray &newValue){

    static float tempx = 0;
    static float tempy = 0;
    static float tempz = 0;
    static int8_t avg = 0;

    float x = *reinterpret_cast<const float*>(newValue.data());
    float y = *reinterpret_cast<const float*>(newValue.data()+4);
    float z = *reinterpret_cast<const float*>(newValue.data()+8);



    tempx += x;
    tempy += y;
    tempz += z;
    avg++;
       if(avg==5) {
           avg = 0;
           tempx = tempx/5;
           tempy = tempy/5;
           tempz = tempz/5;
           qDebug() << "x : " << tempx << " y : " << tempy << " z : " << tempz;
          /* qDebug() << "y : " << tempy;
           qDebug() << "z : " << tempz;*/
           tempx = 0;
           tempy = 0;
           tempz = 0;
       }

}

void Thingy::connectedToDevice(){
   controller->discoverServices();
}

void Thingy::serviceDiscovered(){
   service = controller->createServiceObject(thingyUIService);
   serviceMotion = controller->createServiceObject(thingyMotion);
   connect(service,SIGNAL(stateChanged(QLowEnergyService::ServiceState)),
	   this, SLOT(serviceStateChanged(QLowEnergyService::ServiceState)));
   connect(service,SIGNAL(characteristicChanged(const QLowEnergyCharacteristic&, const QByteArray&)),
           this, SLOT(buttonChanged(const QLowEnergyCharacteristic&, const QByteArray&)));
   connect(serviceMotion,SIGNAL(stateChanged(QLowEnergyService::ServiceState)),
           this, SLOT(serviceMotionStateChanged(QLowEnergyService::ServiceState)));
   connect(serviceMotion,SIGNAL(characteristicChanged(const QLowEnergyCharacteristic&, const QByteArray&)),
           this, SLOT(motionChanged(const QLowEnergyCharacteristic&, const QByteArray&)));
   service->discoverDetails();
   serviceMotion->discoverDetails();
}

void Thingy::serviceStateChanged(QLowEnergyService::ServiceState newState){
   qDebug() << newState;
   switch(newState){
   case QLowEnergyService::ServiceDiscovered:{
   	btn = service->characteristic(thingyButtonState);
   	led = service->characteristic(thingyLedControl);
   	setNotify_(*service,btn,true);
   	setNotify_(*service,led,true);
	changeColor(Qt::blue);
	break;
        }

   default:{
	break;
        }
   }
}

void Thingy::serviceMotionStateChanged(QLowEnergyService::ServiceState newState){
    qDebug() << newState;
    switch(newState){
        case QLowEnergyService::ServiceDiscovered:{
            acc = serviceMotion->characteristic(thingyAcc);
            setNotify_(*serviceMotion,acc,true);
            break;
        }

        default:{
            break;
        }
    }
}
bool Thingy::setNotify_(QLowEnergyService& serv, const QLowEnergyCharacteristic& charact, bool en){
   auto notifyDescriptor = charact.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
   if(!notifyDescriptor.isValid()){
	   return false;
   }
   serv.writeDescriptor(notifyDescriptor, QByteArray().append(static_cast<char>(en ? 1U : 0U)).append(static_cast<char>(0U)));
   return true;
}

