#include "myplaylist.h"

MyPlaylist::MyPlaylist(QObject *parent) : QObject(parent)
{
}

// 添加媒体文件到列表
void MyPlaylist::addMedia(const QUrl &content)
{
    m_mediaList.append(content);
    // 若当前无选中索引，默认选中第一个
    if (m_currentIndex == -1 && !m_mediaList.isEmpty()) {
        m_currentIndex = 0;
    }
}

// 设置播放模式
void MyPlaylist::setPlaybackMode(PlaybackMode mode)
{
    m_playMode = mode;
}

// 设置当前播放索引（对应原 setCurrentIndex）
void MyPlaylist::setCurrentIndex(int index)
{
    // 索引有效性检查
    if (index >= 0 && index < m_mediaList.size()) {
        m_currentIndex = index;
    }
}

// 获取当前索引
int MyPlaylist::currentIndex() const
{
    return m_currentIndex;
}

// 获取媒体文件总数
int MyPlaylist::mediaCount() const
{
    return m_mediaList.size();
}

// 获取当前媒体文件
QUrl MyPlaylist::currentMedia() const
{
    if (m_currentIndex >= 0 && m_currentIndex < m_mediaList.size()) {
        return m_mediaList[m_currentIndex];
    }
    return QUrl();
}

// 切换到下一个媒体（播放结束时调用）
void MyPlaylist::next()
{
    if (m_mediaList.isEmpty()) return;

    switch (m_playMode) {
    case CurrentItemOnce:
        // 单曲一次：播放结束后停止（索引不变，播放器自然停止）
        m_currentIndex = -1;
        break;
    case CurrentItemInLoop:
        // 单曲循环：保持当前索引（播放器会重新播放）
        break;
    case Sequential:
        // 顺序播放：切换到下一个，最后一个则停止
        if (m_currentIndex < m_mediaList.size() - 1) {
            m_currentIndex++;
        } else {
            m_currentIndex = -1;  // 标记为结束
        }
        break;
    case Loop:
        // 循环播放：切换到下一个，最后一个则回到第一个
        m_currentIndex = (m_currentIndex + 1) % m_mediaList.size();
        break;
    }
}
