/****************************************************************************
** Meta object code from reading C++ file 'PBR_Renderer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PBR_Renderer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PBR_Renderer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PBR_Renderer_t {
    QByteArrayData data[13];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PBR_Renderer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PBR_Renderer_t qt_meta_stringdata_PBR_Renderer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PBR_Renderer"
QT_MOC_LITERAL(1, 13, 9), // "AddSphere"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "AddCube"
QT_MOC_LITERAL(4, 32, 14), // "ShowProperties"
QT_MOC_LITERAL(5, 47, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 59, 5), // "index"
QT_MOC_LITERAL(7, 65, 11), // "ShowPartone"
QT_MOC_LITERAL(8, 77, 14), // "UnlockMaterial"
QT_MOC_LITERAL(9, 92, 13), // "UnlockDiffuse"
QT_MOC_LITERAL(10, 106, 14), // "UnlockSpecular"
QT_MOC_LITERAL(11, 121, 8), // "AddModel"
QT_MOC_LITERAL(12, 130, 20) // "AddEnviromentTexture"

    },
    "PBR_Renderer\0AddSphere\0\0AddCube\0"
    "ShowProperties\0QModelIndex\0index\0"
    "ShowPartone\0UnlockMaterial\0UnlockDiffuse\0"
    "UnlockSpecular\0AddModel\0AddEnviromentTexture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PBR_Renderer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    1,   61,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PBR_Renderer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PBR_Renderer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddSphere(); break;
        case 1: _t->AddCube(); break;
        case 2: _t->ShowProperties((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->ShowPartone(); break;
        case 4: _t->UnlockMaterial(); break;
        case 5: _t->UnlockDiffuse(); break;
        case 6: _t->UnlockSpecular(); break;
        case 7: _t->AddModel(); break;
        case 8: _t->AddEnviromentTexture(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PBR_Renderer::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_PBR_Renderer.data,
    qt_meta_data_PBR_Renderer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PBR_Renderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PBR_Renderer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PBR_Renderer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PBR_Renderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
