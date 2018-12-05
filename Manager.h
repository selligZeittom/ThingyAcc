#ifndef MANAGER_H
#define MANAGER_H
#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QList>
#include <QBluetoothDeviceInfo>
#include <QEventLoop>
#include <QLowEnergyCharacteristic>
#include <QByteArray>
#include <QBluetoothAddress>

class Thingy;

class Manager:public QObject{
   Q_OBJECT
public:
   Manager();
   ~Manager();
   void discoverDevices();
   void createThingy();

private:
   QBluetoothDeviceDiscoveryAgent agent;
   QList<QBluetoothDeviceInfo> devices;
   QEventLoop loop;
   QList<Thingy*> thingys;

   
public slots:
   void buttonStateChanged(const QLowEnergyCharacteristic& characteristic,
		           const QByteArray &newValue,
			   const QBluetoothAddress &address);
};

#endif // MANAGER_H
