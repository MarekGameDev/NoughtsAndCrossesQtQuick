#include "game.h"
#include <QDebug>


Game::Game(QObject* parent) : QObject(parent)
{

}

QVector<int> Game::playerPoints() const { return m_playersPoints; }
QVector<int> Game::fields() const { return m_fields; }
QVector<QString> Game::sources() const { return m_sources; }
QString Game::result() const { return m_gameResult; }
bool Game::gameFinished() const { return m_gameFinished; }

void Game::setGameFinished(bool fin)
{
    if (m_gameFinished == fin)
        return;

    m_gameFinished = fin;
    emit gameFinishedChanged(m_gameFinished);
}

void Game::setResult(QString res)
{
    if (m_gameResult == res)
        return;

    m_gameResult = res;
    emit resultChanged(m_gameResult);
}
void Game::setCounter(QVector<int> counter)
{
    if (m_fields == counter)
        return;

    m_fields = counter;
    emit counterChanged(m_fields);
}
void Game::setSources(QVector<QString> sources)
{
    if (m_sources == sources)
        return;

    m_sources = sources;
    emit sourcesChanged(m_sources);
}
void Game::setPlayerPoints(QVector<int> pPoints)
{
    if (m_playersPoints == pPoints)
        return;

    m_playersPoints = pPoints;
    emit playerPointsChanged(m_playersPoints);
}




void Game::onStartGame()
{
    for(int& field : m_fields) {
        field = -1;
    }
    for(QString& source : m_sources) {
        source = "";
    }
    m_gameFinished = false;
    emit counterChanged(m_fields);
    emit playerPointsChanged(m_playersPoints);
    emit sourcesChanged(m_sources);
    emit resultChanged(m_gameResult);
    emit gameFinishedChanged(m_gameFinished);
}
void Game::onFieldClicked(int index)
{
    if(m_fields[index]>-1 || m_gameFinished==true) return;

    qDebug() << "onFieldClicked: " << index;
    m_fields[index] = currentPlayer;
    m_sources[index] = playerImage[currentPlayer];
    emit counterChanged(m_fields);
    emit sourcesChanged(m_sources);

    currentPlayer==1 ? currentPlayer=0 : currentPlayer=1;


    if( isGameFinished() ) {
        QVector<int> winSeq ( getWinnerArray() );
        for(int a=0; a<winSeq.size(); a++) {
            m_fields[a] = winSeq[a];
            if(winSeq[a]==-1) m_sources[a] = "";
        }
            qDebug() << "KONIEC GRY";
            emit playerPointsChanged(m_playersPoints);
            emit counterChanged(m_fields);
            emit resultChanged(m_gameResult);
            emit gameFinishedChanged(m_gameFinished);
           // onStartGame();

    } else {

        qDebug() << "GRA TRWA";
    }

}



QVector<int> Game::getWinnerArray()
{
    QVector<int> winnerFields = { -1,-1,-1,
                                 -1,-1,-1,
                                 -1,-1,-1 };
    QVector<QVector<int>> winSequences = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{6,4,2}
    };
    for(QVector<int> winS : winSequences ) {

        if( m_fields[winS[0]] == m_fields[winS[1]] &&
            m_fields[winS[0]] == m_fields[winS[2]] &&
            m_fields[winS[0]]!=-1 ) {
            qDebug() << "TAK: " << m_fields[winS[0]] << " " << m_fields[winS[1]] << " " << m_fields[winS[2]];
            qDebug() << "   : " << winnerFields.size() << " " << winS[0] << " " << winS[1] << " " << winS[2];

            winnerFields[winS[0]] = m_fields[winS[0]];
            winnerFields[winS[1]] = m_fields[winS[1]];
            winnerFields[winS[2]] = m_fields[winS[2]];

            m_playersPoints[ m_fields[winS[0]] ] ++;
           return winnerFields;
        } else {
            qDebug() << "NIE: " << m_fields[winS[0]] << " " << m_fields[winS[1]] << " " << m_fields[winS[2]];

        }
    }
    return winnerFields;
}
bool Game::isGameFinished()
{
    QVector<QVector<int>> winSequences = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{6,4,2}
    };
    for(QVector<int> winS : winSequences ) {

        if( m_fields[winS[0]] == m_fields[winS[1]] &&
            m_fields[winS[0]] == m_fields[winS[2]] &&
            m_fields[winS[0]]!=-1 ) {

            if(m_fields[winS[0]]==0) {
                m_gameResult = "Player 1 win";
            } else {
                m_gameResult = "Player 2 win";
            }
            m_gameFinished=true;
            return true;

        }
    }
    int checkledFields = 0;
    for(int field : m_fields) {
        if(field>-1) checkledFields++;
        if(checkledFields==9) {
            m_gameResult = "Draw";
            m_gameFinished=true;
            return true;
        }
    }
    return false;
}



