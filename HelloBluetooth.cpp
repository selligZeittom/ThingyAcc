#include <QCoreApplication>
#include "Manager.h"

int main(int argc, char** argv){
	QCoreApplication application(argc,argv);
	Manager m;
	m.discoverDevices();
	m.createThingy();
	application.exec();

	return 1;
}
