/****************************************************************************
** Meta object code from reading C++ file 'BCI_mainWindow.h'
**
** Created: Fri 15. May 11:56:46 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../apps/EPOC_GYRO_GUI/BCI_mainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCI_mainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BCI_mainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      34,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BCI_mainWindow[] = {
    "BCI_mainWindow\0\0menuAbout_Click()\0"
    "menuClose_Click()\0"
};

void BCI_mainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BCI_mainWindow *_t = static_cast<BCI_mainWindow *>(_o);
        switch (_id) {
        case 0: _t->menuAbout_Click(); break;
        case 1: _t->menuClose_Click(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BCI_mainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BCI_mainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BCI_mainWindow,
      qt_meta_data_BCI_mainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BCI_mainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BCI_mainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BCI_mainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BCI_mainWindow))
        return static_cast<void*>(const_cast< BCI_mainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BCI_mainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
