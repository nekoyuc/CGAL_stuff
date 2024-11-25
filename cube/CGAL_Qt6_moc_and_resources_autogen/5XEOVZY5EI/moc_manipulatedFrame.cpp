/****************************************************************************
** Meta object code from reading C++ file 'manipulatedFrame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../opt/homebrew/include/CGAL/Qt/manipulatedFrame.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manipulatedFrame.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPEManipulatedFrameENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPEManipulatedFrameENDCLASS = QtMocHelpers::stringData(
    "CGAL::qglviewer::ManipulatedFrame",
    "manipulated",
    "",
    "spun",
    "setRotationSensitivity",
    "sensitivity",
    "setTranslationSensitivity",
    "setSpinningSensitivity",
    "setWheelSensitivity",
    "setZoomSensitivity",
    "setSpinningQuaternion",
    "Quaternion",
    "spinningQuaternion",
    "startSpinning",
    "updateInterval",
    "stopSpinning",
    "spin",
    "spinUpdate"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCGALSCOPEqglviewerSCOPEManipulatedFrameENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    0,   87,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   88,    2, 0x0a,    3 /* Public */,
       6,    1,   91,    2, 0x0a,    5 /* Public */,
       7,    1,   94,    2, 0x0a,    7 /* Public */,
       8,    1,   97,    2, 0x0a,    9 /* Public */,
       9,    1,  100,    2, 0x0a,   11 /* Public */,
      10,    1,  103,    2, 0x0a,   13 /* Public */,
      13,    1,  106,    2, 0x0a,   15 /* Public */,
      15,    0,  109,    2, 0x0a,   17 /* Public */,
      16,    0,  110,    2, 0x09,   18 /* Protected */,
      17,    0,  111,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CGAL::qglviewer::ManipulatedFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<Frame::staticMetaObject>(),
    qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPEManipulatedFrameENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCGALSCOPEqglviewerSCOPEManipulatedFrameENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPEManipulatedFrameENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ManipulatedFrame, std::true_type>,
        // method 'manipulated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'spun'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setRotationSensitivity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setTranslationSensitivity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSpinningSensitivity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setWheelSensitivity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setZoomSensitivity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSpinningQuaternion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Quaternion &, std::false_type>,
        // method 'startSpinning'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'stopSpinning'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'spin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'spinUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CGAL::qglviewer::ManipulatedFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManipulatedFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->manipulated(); break;
        case 1: _t->spun(); break;
        case 2: _t->setRotationSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 3: _t->setTranslationSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 4: _t->setSpinningSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 5: _t->setWheelSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 6: _t->setZoomSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 7: _t->setSpinningQuaternion((*reinterpret_cast< std::add_pointer_t<Quaternion>>(_a[1]))); break;
        case 8: _t->startSpinning((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->stopSpinning(); break;
        case 10: _t->spin(); break;
        case 11: _t->spinUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ManipulatedFrame::*)();
            if (_t _q_method = &ManipulatedFrame::manipulated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ManipulatedFrame::*)();
            if (_t _q_method = &ManipulatedFrame::spun; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *CGAL::qglviewer::ManipulatedFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGAL::qglviewer::ManipulatedFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPEManipulatedFrameENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "MouseGrabber"))
        return static_cast< MouseGrabber*>(this);
    return Frame::qt_metacast(_clname);
}

int CGAL::qglviewer::ManipulatedFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Frame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CGAL::qglviewer::ManipulatedFrame::manipulated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CGAL::qglviewer::ManipulatedFrame::spun()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
