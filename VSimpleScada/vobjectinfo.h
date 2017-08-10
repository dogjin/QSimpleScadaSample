#ifndef VOBJECTINFO_H
#define VOBJECTINFO_H

#include "vobjectinfoaxis.h"

#include <QObject>
#include <QColor>
#include <QRect>


typedef enum {
    VObjectActionNone,
    VObjectActionMove,
    VObjectActionResize
} VObjectAction;

typedef enum {
    VObjectStatusNone,
    VObjectStatusRed,
    VObjectStatusYellow,
    VObjectStatusGreen
} VObjectStatus;


typedef enum {
    VObjectAxisPositionLeft,
    VObjectAxisPositionRight
} VObjectAxisPosition;

struct VObjectInfoImage {
    QString normal = ":/VSimpleScada/resources/grey_marker.png";
    QString green = ":/VSimpleScada/resources/green_marker.png";
    QString yellow = ":/VSimpleScada/resources/yellow_marker.png";
    QString red = ":/VSimpleScada/resources/red_marker.png";

    QString getImageNameForStatus(VObjectStatus);
    void setImageNameForState(QString, VObjectStatus);
};

class VObjectInfo : public QObject
{
    Q_OBJECT
public:
    explicit VObjectInfo(QObject *parent = 0);

    int id() const;
    void setId(int id);

    QString title() const;
    void setTitle(const QString &title);

    VObjectInfoAxis axis() const;
    void setAxis(const VObjectInfoAxis &axis);

    bool axiesEnabled() const;
    void setAxiesEnabled(bool axiesEnabled);

    QRect geometry() const;
    void setGeometry(const QRect &geometry);

    bool isDynamic() const;
    void setIsDynamic(bool isDynamic);

    QString imageName(VObjectStatus);
    void setImageName(QString imageName, VObjectStatus);

    bool showBackground() const;
    void setShowBackground(bool showBackground);

    bool showMarkers() const;
    void setShowMarkers(bool showMarkers);

    VObjectAxisPosition axisPosition() const;
    void setAxisPosition(const VObjectAxisPosition &axisPosition);

    QString backGroundImage() const;
    void setBackGroundImage(const QString &backGroundImage);

    bool showBackgroundImage() const;
    void setShowBackgroundImage(bool showBackgroundImage);

signals:
    void infoChanged(VObjectInfo *info);
    void geometryChanged(VObjectInfo *info);
    void dynamicStatusChanged(VObjectInfo *info);

private:
    bool mIsDynamic; //by default false
    QRect mGeometry;
    int mId;
    QString mTitle;
    VObjectInfoAxis mAxis;
    bool mAxiesEnabled;
    VObjectAxisPosition mAxisPosition;

    VObjectInfoImage mImageName;
    QString mBackGroundImage;
    bool mShowBackgroundImage;
    bool mShowBackground;
    bool mShowMarkers;
};

#endif // VOBJECTINFO_H
