/****************************************************************************
** Meta object code from reading C++ file 'Render.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Render.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Render.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Render_t {
    QByteArrayData data[42];
    char stringdata0[598];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Render_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Render_t qt_meta_stringdata_Render = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Render"
QT_MOC_LITERAL(1, 7, 9), // "SetMeshUI"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "Model*"
QT_MOC_LITERAL(4, 25, 7), // "pointer"
QT_MOC_LITERAL(5, 33, 10), // "SetLightUI"
QT_MOC_LITERAL(6, 44, 1), // "i"
QT_MOC_LITERAL(7, 46, 15), // "ChangePositionX"
QT_MOC_LITERAL(8, 62, 4), // "text"
QT_MOC_LITERAL(9, 67, 15), // "ChangePositionY"
QT_MOC_LITERAL(10, 83, 15), // "ChangePositionZ"
QT_MOC_LITERAL(11, 99, 12), // "ChangeScaleX"
QT_MOC_LITERAL(12, 112, 12), // "ChangeScaleY"
QT_MOC_LITERAL(13, 125, 12), // "ChangeScaleZ"
QT_MOC_LITERAL(14, 138, 15), // "ChangeRotationX"
QT_MOC_LITERAL(15, 154, 15), // "ChangeRotationY"
QT_MOC_LITERAL(16, 170, 15), // "ChangeRotationZ"
QT_MOC_LITERAL(17, 186, 12), // "ChangeColorR"
QT_MOC_LITERAL(18, 199, 12), // "ChangeColorG"
QT_MOC_LITERAL(19, 212, 12), // "ChangeColorB"
QT_MOC_LITERAL(20, 225, 14), // "ChangeMetallic"
QT_MOC_LITERAL(21, 240, 15), // "ChangeRoughness"
QT_MOC_LITERAL(22, 256, 8), // "ChangeAO"
QT_MOC_LITERAL(23, 265, 12), // "SettextureON"
QT_MOC_LITERAL(24, 278, 5), // "value"
QT_MOC_LITERAL(25, 284, 16), // "SetPBRMaterialON"
QT_MOC_LITERAL(26, 301, 20), // "SetIndirectDiffuseON"
QT_MOC_LITERAL(27, 322, 21), // "SetIndirectSpecularON"
QT_MOC_LITERAL(28, 344, 15), // "SetPLightONOFF1"
QT_MOC_LITERAL(29, 360, 15), // "SetPLightONOFF2"
QT_MOC_LITERAL(30, 376, 19), // "SetPlightPositionX1"
QT_MOC_LITERAL(31, 396, 19), // "SetPlightPositionY1"
QT_MOC_LITERAL(32, 416, 19), // "SetPlightPositionZ1"
QT_MOC_LITERAL(33, 436, 19), // "SetPlightPositionX2"
QT_MOC_LITERAL(34, 456, 19), // "SetPlightPositionY2"
QT_MOC_LITERAL(35, 476, 19), // "SetPlightPositionZ2"
QT_MOC_LITERAL(36, 496, 16), // "SetPlightColorR1"
QT_MOC_LITERAL(37, 513, 16), // "SetPlightColorG1"
QT_MOC_LITERAL(38, 530, 16), // "SetPlightColorB1"
QT_MOC_LITERAL(39, 547, 16), // "SetPlightColorR2"
QT_MOC_LITERAL(40, 564, 16), // "SetPlightColorG2"
QT_MOC_LITERAL(41, 581, 16) // "SetPlightColorB2"

    },
    "Render\0SetMeshUI\0\0Model*\0pointer\0"
    "SetLightUI\0i\0ChangePositionX\0text\0"
    "ChangePositionY\0ChangePositionZ\0"
    "ChangeScaleX\0ChangeScaleY\0ChangeScaleZ\0"
    "ChangeRotationX\0ChangeRotationY\0"
    "ChangeRotationZ\0ChangeColorR\0ChangeColorG\0"
    "ChangeColorB\0ChangeMetallic\0ChangeRoughness\0"
    "ChangeAO\0SettextureON\0value\0"
    "SetPBRMaterialON\0SetIndirectDiffuseON\0"
    "SetIndirectSpecularON\0SetPLightONOFF1\0"
    "SetPLightONOFF2\0SetPlightPositionX1\0"
    "SetPlightPositionY1\0SetPlightPositionZ1\0"
    "SetPlightPositionX2\0SetPlightPositionY2\0"
    "SetPlightPositionZ2\0SetPlightColorR1\0"
    "SetPlightColorG1\0SetPlightColorB1\0"
    "SetPlightColorR2\0SetPlightColorG2\0"
    "SetPlightColorB2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Render[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  189,    2, 0x06 /* Public */,
       5,    1,  192,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  195,    2, 0x0a /* Public */,
       9,    1,  198,    2, 0x0a /* Public */,
      10,    1,  201,    2, 0x0a /* Public */,
      11,    1,  204,    2, 0x0a /* Public */,
      12,    1,  207,    2, 0x0a /* Public */,
      13,    1,  210,    2, 0x0a /* Public */,
      14,    1,  213,    2, 0x0a /* Public */,
      15,    1,  216,    2, 0x0a /* Public */,
      16,    1,  219,    2, 0x0a /* Public */,
      17,    1,  222,    2, 0x0a /* Public */,
      18,    1,  225,    2, 0x0a /* Public */,
      19,    1,  228,    2, 0x0a /* Public */,
      20,    1,  231,    2, 0x0a /* Public */,
      21,    1,  234,    2, 0x0a /* Public */,
      22,    1,  237,    2, 0x0a /* Public */,
      23,    1,  240,    2, 0x0a /* Public */,
      25,    1,  243,    2, 0x0a /* Public */,
      26,    1,  246,    2, 0x0a /* Public */,
      27,    1,  249,    2, 0x0a /* Public */,
      28,    1,  252,    2, 0x0a /* Public */,
      29,    1,  255,    2, 0x0a /* Public */,
      30,    1,  258,    2, 0x0a /* Public */,
      31,    1,  261,    2, 0x0a /* Public */,
      32,    1,  264,    2, 0x0a /* Public */,
      33,    1,  267,    2, 0x0a /* Public */,
      34,    1,  270,    2, 0x0a /* Public */,
      35,    1,  273,    2, 0x0a /* Public */,
      36,    1,  276,    2, 0x0a /* Public */,
      37,    1,  279,    2, 0x0a /* Public */,
      38,    1,  282,    2, 0x0a /* Public */,
      39,    1,  285,    2, 0x0a /* Public */,
      40,    1,  288,    2, 0x0a /* Public */,
      41,    1,  291,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void Render::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Render *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetMeshUI((*reinterpret_cast< Model*(*)>(_a[1]))); break;
        case 1: _t->SetLightUI((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ChangePositionX((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->ChangePositionY((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->ChangePositionZ((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->ChangeScaleX((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->ChangeScaleY((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->ChangeScaleZ((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->ChangeRotationX((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->ChangeRotationY((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->ChangeRotationZ((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->ChangeColorR((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->ChangeColorG((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->ChangeColorB((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->ChangeMetallic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->ChangeRoughness((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->ChangeAO((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->SettextureON((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->SetPBRMaterialON((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->SetIndirectDiffuseON((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->SetIndirectSpecularON((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->SetPLightONOFF1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->SetPLightONOFF2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->SetPlightPositionX1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->SetPlightPositionY1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->SetPlightPositionZ1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->SetPlightPositionX2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->SetPlightPositionY2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->SetPlightPositionZ2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->SetPlightColorR1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->SetPlightColorG1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->SetPlightColorB1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->SetPlightColorR2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->SetPlightColorG2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->SetPlightColorB2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Render::*)(Model * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Render::SetMeshUI)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Render::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Render::SetLightUI)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Render::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_Render.data,
    qt_meta_data_Render,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Render::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Render::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Render.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions_4_4_Core"))
        return static_cast< QOpenGLFunctions_4_4_Core*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int Render::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void Render::SetMeshUI(Model * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Render::SetLightUI(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
