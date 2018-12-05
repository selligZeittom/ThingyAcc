/****************************************************************************
** Meta object code from reading C++ file 'Thingy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Thingy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Thingy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Thingy_t {
    QByteArrayData data[14];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Thingy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Thingy_t qt_meta_stringdata_Thingy = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Thingy"
QT_MOC_LITERAL(1, 7, 18), // "buttonStateChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(4, 52, 14), // "characteristic"
QT_MOC_LITERAL(5, 67, 8), // "newValue"
QT_MOC_LITERAL(6, 76, 17), // "QBluetoothAddress"
QT_MOC_LITERAL(7, 94, 7), // "address"
QT_MOC_LITERAL(8, 102, 13), // "buttonChanged"
QT_MOC_LITERAL(9, 116, 17), // "connectedToDevice"
QT_MOC_LITERAL(10, 134, 17), // "serviceDiscovered"
QT_MOC_LITERAL(11, 152, 19), // "serviceStateChanged"
QT_MOC_LITERAL(12, 172, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(13, 204, 8) // "newState"

    },
    "Thingy\0buttonStateChanged\0\0"
    "QLowEnergyCharacteristic\0characteristic\0"
    "newValue\0QBluetoothAddress\0address\0"
    "buttonChanged\0connectedToDevice\0"
    "serviceDiscovered\0serviceStateChanged\0"
    "QLowEnergyService::ServiceState\0"
    "newState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Thingy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   46,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x0a /* Public */,
      10,    0,   52,    2, 0x0a /* Public */,
      11,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 6,    4,    5,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void Thingy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Thingy *_t = static_cast<Thingy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonStateChanged((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QBluetoothAddress(*)>(_a[3]))); break;
        case 1: _t->buttonChanged((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 2: _t->connectedToDevice(); break;
        case 3: _t->serviceDiscovered(); break;
        case 4: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothAddress >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Thingy::*_t)(const QLowEnergyCharacteristic & , const QByteArray & , const QBluetoothAddress & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Thingy::buttonStateChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Thingy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Thingy.data,
      qt_meta_data_Thingy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Thingy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Thingy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Thingy.stringdata0))
        return static_cast<void*>(const_cast< Thingy*>(this));
    return QObject::qt_metacast(_clname);
}

int Thingy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Thingy::buttonStateChanged(const QLowEnergyCharacteristic & _t1, const QByteArray & _t2, const QBluetoothAddress & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
