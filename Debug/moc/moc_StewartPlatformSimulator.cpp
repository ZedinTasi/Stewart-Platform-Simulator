/****************************************************************************
** Meta object code from reading C++ file 'StewartPlatformSimulator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StewartPlatformSimulator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StewartPlatformSimulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StewartPlatformSimulator_t {
    QByteArrayData data[7];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StewartPlatformSimulator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StewartPlatformSimulator_t qt_meta_stringdata_StewartPlatformSimulator = {
    {
QT_MOC_LITERAL(0, 0, 24), // "StewartPlatformSimulator"
QT_MOC_LITERAL(1, 25, 9), // "SLOT_CL2L"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 29), // "SLOT_setSliderValueByLineEdit"
QT_MOC_LITERAL(4, 66, 36), // "SLOT_setPlatformParametersByL..."
QT_MOC_LITERAL(5, 103, 14), // "SLOT_UseKeyOff"
QT_MOC_LITERAL(6, 118, 4) // "draw"

    },
    "StewartPlatformSimulator\0SLOT_CL2L\0\0"
    "SLOT_setSliderValueByLineEdit\0"
    "SLOT_setPlatformParametersByLineEdit\0"
    "SLOT_UseKeyOff\0draw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StewartPlatformSimulator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StewartPlatformSimulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StewartPlatformSimulator *_t = static_cast<StewartPlatformSimulator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SLOT_CL2L(); break;
        case 1: _t->SLOT_setSliderValueByLineEdit(); break;
        case 2: _t->SLOT_setPlatformParametersByLineEdit(); break;
        case 3: _t->SLOT_UseKeyOff(); break;
        case 4: _t->draw(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject StewartPlatformSimulator::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StewartPlatformSimulator.data,
      qt_meta_data_StewartPlatformSimulator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StewartPlatformSimulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StewartPlatformSimulator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StewartPlatformSimulator.stringdata0))
        return static_cast<void*>(const_cast< StewartPlatformSimulator*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StewartPlatformSimulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
