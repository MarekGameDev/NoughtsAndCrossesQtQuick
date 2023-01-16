#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>


class Game : public QObject
{
    Q_OBJECT
public:

    int currentPlayer = 0;
    bool m_gameFinished = false;
    QString m_gameResult = "";

    Q_PROPERTY(QVector<int> fields       READ fields       WRITE setCounter      NOTIFY counterChanged)
    Q_PROPERTY(QVector<QString> sources  READ sources      WRITE setSources      NOTIFY sourcesChanged)
    Q_PROPERTY(QVector<int> playerPoints READ playerPoints WRITE setPlayerPoints NOTIFY playerPointsChanged)
    Q_PROPERTY(QString result            READ result       WRITE setResult       NOTIFY resultChanged)
    Q_PROPERTY(bool  gameFinished        READ gameFinished WRITE setGameFinished NOTIFY gameFinishedChanged)

    explicit Game(QObject *parent = nullptr);

    Q_INVOKABLE void onFieldClicked(int index);
    Q_INVOKABLE void onStartGame();

    bool gameFinished() const;
    QString result() const;
    QVector<int> playerPoints() const;
    QVector<int> fields() const;
    QVector<QString> sources() const;

public slots:
    void setGameFinished(bool fin);
    void setResult(QString res);
    void setPlayerPoints(QVector<int> pPoints);
    void setCounter(QVector<int> counter);
    void setSources(QVector<QString> sources);

signals:
    void gameFinishedChanged(bool fin);
    void resultChanged(QString res);
    void playerPointsChanged(QVector<int> pPoints);
    void counterChanged(QVector<int> counter);
    void sourcesChanged(QVector<QString> sources);

private:
    QVector<int> m_fields = { -1,-1,-1,
                            -1,-1,-1,
                            -1,-1,-1 };
    QVector<QString> m_sources = { "","","",
                            "","","",
                            "","","" };

    QVector<QString> playerImage = {
                                    "qrc:/assets/o.png",
                                    "qrc:/assets/x.png"
    };

    QVector<int> m_playersPoints = { 0,0 };

    bool isGameFinished();
    QVector<int> getWinnerArray();

};

#endif // APPCORE_H
