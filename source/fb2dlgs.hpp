#ifndef FB2DLGS_H
#define FB2DLGS_H

#include <QDialog>

class FbCodeEdit;
class FbTextBase;
class FbTextEdit;

QT_BEGIN_NAMESPACE
class QComboBox;
class QLineEdit;
class QToolBar;
class QWebView;
QT_END_NAMESPACE

namespace Ui {
class FbFind;
class FbSetup;
}

class FbCodeFindDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FbCodeFindDlg(FbCodeEdit &edit);
    virtual ~FbCodeFindDlg();

private slots:
    void find();

private:
    Ui::FbFind * ui;
    FbCodeEdit & m_edit;
};

class FbTextFindDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FbTextFindDlg(FbTextEdit &edit);
    virtual ~FbTextFindDlg();

private slots:
    void find();

private:
    Ui::FbFind * ui;
    FbTextEdit & m_edit;
};

class FbNoteDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit FbNoteDlg(FbTextEdit &view);

private slots:
    void loadFinished();

private:
    QComboBox *m_key;
    FbTextBase *m_text;
    QLineEdit *m_title;
    QToolBar *m_toolbar;
};

class FbSetupDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FbSetupDlg(QWidget *parent = 0, Qt::WindowFlags f = 0);

private:
    Ui::FbSetup * ui;
};

#endif // FB2DLGS_H
