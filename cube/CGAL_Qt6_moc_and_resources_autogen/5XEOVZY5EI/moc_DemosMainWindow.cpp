/****************************************************************************
** Meta object code from reading C++ file 'DemosMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../opt/homebrew/include/CGAL/Qt/DemosMainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DemosMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCGALSCOPEQtSCOPEDemosMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCGALSCOPEQtSCOPEDemosMainWindowENDCLASS = QtMocHelpers::stringData(
    "CGAL::Qt::DemosMainWindow",
    "openRecentFile",
    "",
    "filename",
    "setMaxNumberOfRecentFiles",
    "setUseAntialiasing",
    "checked",
    "popupAboutCGAL",
    "popupAboutDemo",
    "exportSVG",
    "openRecentFile_aux",
    "addToRecentFiles",
    "fileName",
    "updateRecentFileActions"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCGALSCOPEQtSCOPEDemosMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   71,    2, 0x0a,    3 /* Public */,
       5,    1,   74,    2, 0x09,    5 /* Protected */,
       7,    0,   77,    2, 0x09,    7 /* Protected */,
       8,    0,   78,    2, 0x09,    8 /* Protected */,
       9,    0,   79,    2, 0x09,    9 /* Protected */,
      10,    0,   80,    2, 0x09,   10 /* Protected */,
      11,    1,   81,    2, 0x09,   11 /* Protected */,
      13,    0,   84,    2, 0x09,   13 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CGAL::Qt::DemosMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSCGALSCOPEQtSCOPEDemosMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCGALSCOPEQtSCOPEDemosMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCGALSCOPEQtSCOPEDemosMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DemosMainWindow, std::true_type>,
        // method 'openRecentFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setMaxNumberOfRecentFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const unsigned int, std::false_type>,
        // method 'setUseAntialiasing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'popupAboutCGAL'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'popupAboutDemo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportSVG'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openRecentFile_aux'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addToRecentFiles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateRecentFileActions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CGAL::Qt::DemosMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DemosMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openRecentFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->setMaxNumberOfRecentFiles((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 2: _t->setUseAntialiasing((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->popupAboutCGAL(); break;
        case 4: _t->popupAboutDemo(); break;
        case 5: _t->exportSVG(); break;
        case 6: _t->openRecentFile_aux(); break;
        case 7: _t->addToRecentFiles((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->updateRecentFileActions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DemosMainWindow::*)(QString );
            if (_t _q_method = &DemosMainWindow::openRecentFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *CGAL::Qt::DemosMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGAL::Qt::DemosMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCGALSCOPEQtSCOPEDemosMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CGAL::Qt::DemosMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CGAL::Qt::DemosMainWindow::openRecentFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
