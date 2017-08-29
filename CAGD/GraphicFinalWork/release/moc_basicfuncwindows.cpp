/****************************************************************************
** Meta object code from reading C++ file 'basicfuncwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../basicfuncwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basicfuncwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_basicFuncWindows_t {
    QByteArrayData data[6];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_basicFuncWindows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_basicFuncWindows_t qt_meta_stringdata_basicFuncWindows = {
    {
QT_MOC_LITERAL(0, 0, 16), // "basicFuncWindows"
QT_MOC_LITERAL(1, 17, 7), // "getInfo"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "Info*"
QT_MOC_LITERAL(4, 32, 1), // "a"
QT_MOC_LITERAL(5, 34, 3) // "clc"

    },
    "basicFuncWindows\0getInfo\0\0Info*\0a\0clc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_basicFuncWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       5,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void basicFuncWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        basicFuncWindows *_t = static_cast<basicFuncWindows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getInfo((*reinterpret_cast< Info*(*)>(_a[1]))); break;
        case 1: _t->clc(); break;
        default: ;
        }
    }
}

const QMetaObject basicFuncWindows::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_basicFuncWindows.data,
      qt_meta_data_basicFuncWindows,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *basicFuncWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *basicFuncWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_basicFuncWindows.stringdata0))
        return static_cast<void*>(const_cast< basicFuncWindows*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int basicFuncWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
