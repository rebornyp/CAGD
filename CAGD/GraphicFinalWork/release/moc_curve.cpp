/****************************************************************************
** Meta object code from reading C++ file 'curve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../curve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Curve_t {
    QByteArrayData data[10];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Curve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Curve_t qt_meta_stringdata_Curve = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Curve"
QT_MOC_LITERAL(1, 6, 15), // "rightBtnClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "messagesToBasic"
QT_MOC_LITERAL(4, 39, 5), // "Info*"
QT_MOC_LITERAL(5, 45, 1), // "i"
QT_MOC_LITERAL(6, 47, 7), // "getInfo"
QT_MOC_LITERAL(7, 55, 8), // "clearAll"
QT_MOC_LITERAL(8, 64, 8), // "editSlot"
QT_MOC_LITERAL(9, 73, 2) // "up"

    },
    "Curve\0rightBtnClicked\0\0messagesToBasic\0"
    "Info*\0i\0getInfo\0clearAll\0editSlot\0up"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Curve[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Curve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Curve *_t = static_cast<Curve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rightBtnClicked(); break;
        case 1: _t->messagesToBasic((*reinterpret_cast< Info*(*)>(_a[1]))); break;
        case 2: _t->getInfo((*reinterpret_cast< Info*(*)>(_a[1]))); break;
        case 3: _t->clearAll(); break;
        case 4: _t->editSlot(); break;
        case 5: _t->up(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Curve::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Curve::rightBtnClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Curve::*_t)(Info * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Curve::messagesToBasic)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Curve::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Curve.data,
      qt_meta_data_Curve,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Curve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Curve::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Curve.stringdata0))
        return static_cast<void*>(const_cast< Curve*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Curve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Curve::rightBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Curve::messagesToBasic(Info * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
