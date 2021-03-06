#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QStatusBar>
#include <QMenuBar>
#include <QLabel>
#include <QFile>
#include <QFileDialog>
#include <QTextEdit>
#include <cstdlib>
#include <QTextStream>
#include <string>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QApplication>

#define NB_MENU 3
enum {FILE_SAVE, DISPLAY, ABOUT};

class Notepad : public QMainWindow
{
    Q_OBJECT
public:
    Notepad(QWidget *parent = nullptr);
    bool open(QString path);
    bool save(QString path);

signals:
    void aboutToClose();

public slots:
    void open_slot();
    void save_slot();
    void save_as_slot();
    void new_file_slot();
    void modify_text();
    void close_slot();
    void font_slot();
    void color_slot();
    void about_dev();

    //interception de fermeture de la fenêtre
    void closeEvent(QCloseEvent *event){
        QWidget::closeEvent(event);
        emit aboutToClose();
    }

private:
    QMenuBar *m_menubar;
    QMenu *m_menu[NB_MENU];

    QTextEdit *m_main;
    QString path = "0";
    bool is_saved = true;

    QStatusBar *m_statusbar;
};

#endif // NOTEPAD_H
