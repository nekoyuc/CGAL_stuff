/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../opt/homebrew/include/CGAL/Qt/camera.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPECameraENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPECameraENDCLASS = QtMocHelpers::stringData(
    "CGAL::qglviewer::Camera",
    "setPosition",
    "",
    "Vec",
    "pos",
    "setOrientation",
    "Quaternion",
    "q",
    "theta",
    "phi",
    "setUpVector",
    "up",
    "noMove",
    "setViewDirection",
    "direction",
    "lookAt",
    "target",
    "showEntireScene",
    "fitSphere",
    "center",
    "radius",
    "fitBoundingBox",
    "min",
    "max",
    "fitScreenRegion",
    "rectangle",
    "centerScene",
    "interpolateToZoomOnPixel",
    "pixel",
    "interpolateToFitScene",
    "interpolateTo",
    "Frame",
    "fr",
    "duration",
    "setType",
    "Type",
    "type",
    "setFieldOfView",
    "fov",
    "setHorizontalFieldOfView",
    "hfov",
    "setFOVToFitScene",
    "setAspectRatio",
    "aspect",
    "setScreenWidthAndHeight",
    "width",
    "height",
    "devicePixelRatio",
    "setZNearCoefficient",
    "coef",
    "setZClippingCoefficient",
    "setOrthoZNear",
    "z",
    "orthoZNear",
    "setSceneRadius",
    "setSceneCenter",
    "setSceneCenterFromPixel",
    "setSceneBoundingBox",
    "setPivotPoint",
    "point",
    "setPivotPointFromPixel",
    "setFrame",
    "ManipulatedCameraFrame*",
    "mcf",
    "setKeyFrameInterpolator",
    "i",
    "KeyFrameInterpolator*",
    "kfi",
    "addKeyFrameToPath",
    "playPath",
    "deletePath",
    "resetPath",
    "setFlySpeed",
    "speed",
    "onFrameModified"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCGALSCOPEqglviewerSCOPECameraENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  254,    2, 0x0a,    1 /* Public */,
       5,    1,  257,    2, 0x0a,    3 /* Public */,
       5,    2,  260,    2, 0x0a,    5 /* Public */,
      10,    2,  265,    2, 0x0a,    8 /* Public */,
      10,    1,  270,    2, 0x2a,   11 /* Public | MethodCloned */,
      13,    1,  273,    2, 0x0a,   13 /* Public */,
      15,    1,  276,    2, 0x0a,   15 /* Public */,
      17,    0,  279,    2, 0x0a,   17 /* Public */,
      18,    2,  280,    2, 0x0a,   18 /* Public */,
      21,    2,  285,    2, 0x0a,   21 /* Public */,
      24,    1,  290,    2, 0x0a,   24 /* Public */,
      26,    0,  293,    2, 0x0a,   26 /* Public */,
      27,    1,  294,    2, 0x0a,   27 /* Public */,
      29,    0,  297,    2, 0x0a,   29 /* Public */,
      30,    2,  298,    2, 0x0a,   30 /* Public */,
      34,    1,  303,    2, 0x0a,   33 /* Public */,
      37,    1,  306,    2, 0x0a,   35 /* Public */,
      39,    1,  309,    2, 0x0a,   37 /* Public */,
      41,    0,  312,    2, 0x0a,   39 /* Public */,
      42,    1,  313,    2, 0x0a,   40 /* Public */,
      44,    3,  316,    2, 0x0a,   42 /* Public */,
      44,    2,  323,    2, 0x2a,   46 /* Public | MethodCloned */,
      48,    1,  328,    2, 0x0a,   49 /* Public */,
      50,    1,  331,    2, 0x0a,   51 /* Public */,
      51,    1,  334,    2, 0x0a,   53 /* Public */,
      53,    0,  337,    2, 0x0a,   55 /* Public */,
      54,    1,  338,    2, 0x0a,   56 /* Public */,
      55,    1,  341,    2, 0x0a,   58 /* Public */,
      56,    1,  344,    2, 0x0a,   60 /* Public */,
      57,    2,  347,    2, 0x0a,   62 /* Public */,
      58,    1,  352,    2, 0x0a,   65 /* Public */,
      60,    1,  355,    2, 0x0a,   67 /* Public */,
      61,    1,  358,    2, 0x0a,   69 /* Public */,
      64,    2,  361,    2, 0x0a,   71 /* Public */,
      68,    1,  366,    2, 0x0a,   74 /* Public */,
      69,    1,  369,    2, 0x0a,   76 /* Public */,
      70,    1,  372,    2, 0x0a,   78 /* Public */,
      71,    1,  375,    2, 0x0a,   80 /* Public */,
      72,    1,  378,    2, 0x0a,   82 /* Public */,
      74,    0,  381,    2, 0x08,   84 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    8,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,   11,   12,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void, 0x80000000 | 3,   14,
    QMetaType::Void, 0x80000000 | 3,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QReal,   19,   20,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   22,   23,
    QMetaType::Void, QMetaType::QRect,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   28,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31, QMetaType::QReal,   32,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, QMetaType::QReal,   38,
    QMetaType::Void, QMetaType::QReal,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QReal,   45,   46,   47,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   46,
    QMetaType::Void, QMetaType::QReal,   49,
    QMetaType::Void, QMetaType::QReal,   49,
    QMetaType::Void, QMetaType::QReal,   52,
    QMetaType::QReal,
    QMetaType::Void, QMetaType::QReal,   20,
    QMetaType::Void, 0x80000000 | 3,   19,
    QMetaType::Bool, QMetaType::QPoint,   28,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   22,   23,
    QMetaType::Void, 0x80000000 | 3,   59,
    QMetaType::Bool, QMetaType::QPoint,   28,
    QMetaType::Void, 0x80000000 | 62,   63,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 66,   65,   67,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void, QMetaType::QReal,   73,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CGAL::qglviewer::Camera::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPECameraENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCGALSCOPEqglviewerSCOPECameraENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPECameraENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Camera, std::true_type>,
        // method 'setPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setOrientation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Quaternion &, std::false_type>,
        // method 'setOrientation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setUpVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setUpVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setViewDirection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'lookAt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'showEntireScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fitSphere'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'fitBoundingBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'fitScreenRegion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRect &, std::false_type>,
        // method 'centerScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'interpolateToZoomOnPixel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'interpolateToFitScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'interpolateTo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Frame &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Type, std::false_type>,
        // method 'setFieldOfView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setHorizontalFieldOfView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setFOVToFitScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setAspectRatio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setScreenWidthAndHeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setScreenWidthAndHeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setZNearCoefficient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setZClippingCoefficient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setOrthoZNear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'orthoZNear'
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSceneRadius'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSceneCenter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setSceneCenterFromPixel'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'setSceneBoundingBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setPivotPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setPivotPointFromPixel'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'setFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ManipulatedCameraFrame * const, std::false_type>,
        // method 'setKeyFrameInterpolator'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        QtPrivate::TypeAndForceComplete<KeyFrameInterpolator * const, std::false_type>,
        // method 'addKeyFrameToPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'playPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'deletePath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'resetPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'setFlySpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'onFrameModified'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CGAL::qglviewer::Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Camera *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setPosition((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 1: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<Quaternion>>(_a[1]))); break;
        case 2: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 3: _t->setUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->setUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 5: _t->setViewDirection((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 6: _t->lookAt((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 7: _t->showEntireScene(); break;
        case 8: _t->fitSphere((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 9: _t->fitBoundingBox((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Vec>>(_a[2]))); break;
        case 10: _t->fitScreenRegion((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 11: _t->centerScene(); break;
        case 12: _t->interpolateToZoomOnPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 13: _t->interpolateToFitScene(); break;
        case 14: _t->interpolateTo((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 15: _t->setType((*reinterpret_cast< std::add_pointer_t<Type>>(_a[1]))); break;
        case 16: _t->setFieldOfView((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 17: _t->setHorizontalFieldOfView((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 18: _t->setFOVToFitScene(); break;
        case 19: _t->setAspectRatio((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 20: _t->setScreenWidthAndHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 21: _t->setScreenWidthAndHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 22: _t->setZNearCoefficient((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 23: _t->setZClippingCoefficient((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 24: _t->setOrthoZNear((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 25: { qreal _r = _t->orthoZNear();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->setSceneRadius((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 27: _t->setSceneCenter((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 28: { bool _r = _t->setSceneCenterFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: _t->setSceneBoundingBox((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Vec>>(_a[2]))); break;
        case 30: _t->setPivotPoint((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 31: { bool _r = _t->setPivotPointFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->setFrame((*reinterpret_cast< std::add_pointer_t<ManipulatedCameraFrame*>>(_a[1]))); break;
        case 33: _t->setKeyFrameInterpolator((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<KeyFrameInterpolator*>>(_a[2]))); break;
        case 34: _t->addKeyFrameToPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 35: _t->playPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 36: _t->deletePath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 37: _t->resetPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 38: _t->setFlySpeed((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 39: _t->onFrameModified(); break;
        default: ;
        }
    }
}

const QMetaObject *CGAL::qglviewer::Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGAL::qglviewer::Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCGALSCOPEqglviewerSCOPECameraENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CGAL::qglviewer::Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 40;
    }
    return _id;
}
QT_WARNING_POP
