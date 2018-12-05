#ifndef THINGY_H
#define THINGY_H
#include <QObject>
#include <QString>
#include <QBluetoothAddress>
#include <QBluetoothUuid>
#include <QBluetoothDeviceInfo>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QLowEnergyCharacteristic>
#include <QByteArray>
#include <QList>

   static const QBluetoothUuid thingyAdvertise(QStringLiteral("ef680100-9b35-4933-9b10-52ffa9740042"));
   static const QBluetoothUuid thingyUIService(QStringLiteral("ef680300-9b35-4933-9b10-52ffa9740042"));
   static const QBluetoothUuid thingyButtonState(QStringLiteral("ef680302-9b35-4933-9b10-52ffa9740042"));
   static const QBluetoothUuid thingyLedControl(QStringLiteral("ef680301-9b35-4933-9b10-52ffa9740042"));
   static const QBluetoothUuid thingyMotion(QStringLiteral("ef680400-9b35-4933-9b10-52ffa9740042"));
   static const QBluetoothUuid thingyAcc(QStringLiteral("ef68040a-9b35-4933-9b10-52ffa9740042"));
   static const QBluetoothAddress a1("D9:75:95:5C:B9:E6");
   static const QBluetoothAddress a2("DF:CB:A0:71:A8:6C");

class Thingy: public QObject{
   Q_OBJECT
public:
   Thingy();
   Thingy(QBluetoothAddress ad);
   ~Thingy();
   void setAddress(QBluetoothAddress ad);
   QBluetoothAddress getAddress();
   void setInfo(QBluetoothDeviceInfo i);
   QBluetoothDeviceInfo getInfo();
   void setController(QLowEnergyController* ctrl);
   QLowEnergyController* getController();
   void addService(QLowEnergyService* serv);
   bool setNotify_(QLowEnergyService& serv, const QLowEnergyCharacteristic& charact, bool en);
   void changeColor(Qt::GlobalColor color);
   void switchOffLed();

private:
    QBluetoothAddress address;
    QBluetoothDeviceInfo info;
    QLowEnergyController* controller;
    QLowEnergyService* service;
    QLowEnergyService* serviceMotion;
    QLowEnergyCharacteristic btn;
    QLowEnergyCharacteristic led;
    QLowEnergyCharacteristic acc;

public slots:
    void buttonChanged(const QLowEnergyCharacteristic &characteristic,
                       const QByteArray &newValue);
    void motionChanged(const QLowEnergyCharacteristic &characteristic,
                       const QByteArray &newValue);
    void connectedToDevice();
    void serviceDiscovered();
    void serviceStateChanged(QLowEnergyService::ServiceState newState);
    void serviceMotionStateChanged(QLowEnergyService::ServiceState newState);

signals:
   void buttonStateChanged(const QLowEnergyCharacteristic &characteristic,
		 	   const QByteArray &newValue,
		 	   const QBluetoothAddress &address);

};

#endif // THINGY_H
