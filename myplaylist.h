#ifndef MYPLAYLIST_H
#define MYPLAYLIST_H

#include <QObject>
#include <QMediaPlayer>
#include <QList>
#include <QUrl>

// 完全复刻 QMediaPlaylist 的播放模式枚举
enum PlaybackMode {
    CurrentItemOnce,    // 播放当前项一次后停止
    CurrentItemInLoop,  // 循环播放当前项
    Sequential,         // 顺序播放所有项，结束后停止
    Loop                // 循环播放所有项
};

class MyPlaylist : public QObject
{
    Q_OBJECT
public:
    explicit MyPlaylist(QObject *parent = nullptr);

    // 复刻 QMediaPlaylist 核心接口
    void addMedia(const QUrl &content);
    void setPlaybackMode(PlaybackMode mode);
    void setCurrentIndex(int index);
    int currentIndex() const;
    int mediaCount() const;
    QUrl currentMedia() const;

public slots:
    // 播放下一个（用于顺序/循环模式）
    void next();

private:
    QList<QUrl> m_mediaList;  // 存储媒体文件列表
    PlaybackMode m_playMode = CurrentItemOnce;  // 默认播放模式
    int m_currentIndex = -1;  // 当前播放索引（初始为无效值）
};

#endif // MYPLAYLIST_H
