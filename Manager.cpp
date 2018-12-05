#include "Manager.h"
#include "Thingy.h"
#include <QDebug>

Manager::Manager(){

}

Manager::~Manager(){

}

void Manager::discoverDevices(){
    connect(&agent, SIGNAL(finished()), &loop, SLOT(quit()));
    agent.start();
    loop.exec();
    int i = 0;
    for (auto device: agent.discoveredDevices()){
	if(device.serviceUuids().contains(thingyAdvertise)){
	    if(device.address() == a1 || device.address() == a2)
	    {
	     devices << device;
	     qDebug() << devices[i].name() << devices[i].address() << devices[i].rssi();
	     i++;
	    }
	 }
    }
}

void Manager::createThingy(){
   
foreach(QBluetoothDeviceInfo info, devices){
   Thingy* t = new Thingy(info.address());
   t->setInfo(info);
   thingys << t;
   connect(t, SIGNAL(buttonStateChanged(const QLowEnergyCharacteristic&,
				         const QByteArray&,
					 const QBluetoothAddress&)),
           this, SLOT(buttonStateChanged(const QLowEnergyCharacteristic&,
				         const QByteArray&,
					 const QBluetoothAddress&)));
}
}

void Manager::buttonStateChanged(const QLowEnergyCharacteristic& charact,
		                 const QByteArray& newValue,
				 const QBluetoothAddress& address){
   foreach(Thingy* t , thingys){
	if((int)newValue[0] == 1){
	   if(t->getAddress() == address){
		t->changeColor(Qt::green);
	   }
	   else{
		t->changeColor(Qt::red);
	   }
	}
        else{
	   t->switchOffLed();
	}
   }
}
