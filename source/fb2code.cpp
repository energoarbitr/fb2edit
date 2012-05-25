#include "fb2code.h"

/////////////////////////////////////////////////////////////////////////////
//
//  http://qtcoder.blogspot.com/2010/10/qscintills.html
//  http://www.riverbankcomputing.co.uk/static/Docs/QScintilla2/classQsciScintilla.html
//
/////////////////////////////////////////////////////////////////////////////

#include <Qsci/qscilexerxml.h>

Fb2Scintilla::Fb2Scintilla(QWidget *parent) :
    QsciScintilla(parent)
{
    zoomTo(1);
    setUtf8(true);
    setCaretLineVisible(true);
    setCaretLineBackgroundColor(QColor("gainsboro"));
//    setWrapMode(QsciScintilla::WrapWord);

    setAutoIndent(true);
    setIndentationGuides(true);

    //setup autocompletion
    setAutoCompletionSource(QsciScintilla::AcsAll);
    setAutoCompletionCaseSensitivity(true);
    setAutoCompletionReplaceWord(true);
    setAutoCompletionShowSingle(true);
    setAutoCompletionThreshold(2);

    //setup margins
    setMarginsBackgroundColor(QColor("gainsboro"));
    setMarginLineNumbers(0, true);
    setFolding(QsciScintilla::BoxedFoldStyle, 1);

    //setup brace matching
    setBraceMatching(QsciScintilla::SloppyBraceMatch);
    setMatchedBraceBackgroundColor(Qt::yellow);
    setUnmatchedBraceForegroundColor(Qt::blue);

//    this->setFolding(QsciScintilla::CircledTreeFoldStyle, 1);
    this->setIndentation(true,4);
    this->setAutoIndent(true);

    //setup end-of-line mode
    #if defined Q_WS_X11
    this->setEolMode(QsciScintilla::EolUnix);
    #elif defined Q_WS_WIN
    this->setEolMode(QsciScintilla::EolWindows);
    #elif defined Q_WS_MAC
    this->setEolMode(QsciScintilla::EolMac);
    #endif

    //setup auto-indentation
    this->setAutoIndent(true);
    this->setIndentationGuides(true);
    this->setIndentationsUseTabs(false);
    this->setIndentationWidth(2);

    QsciLexerXML * lexer = new QsciLexerXML;
    lexer->setFoldPreprocessor(true);

    #ifdef Q_WS_WIN
    lexer->setFont(QFont("Courier New", 8));
    #else
    lexer->setFont(QFont("Monospace", 8));
    #endif

    setLexer(lexer);

    connect(this, SIGNAL(linesChanged()), SLOT(linesChanged()));
}

void Fb2Scintilla::linesChanged()
{
    QString width = QString().setNum(lines() * 10);
    setMarginWidth(0, width);
}

void Fb2Scintilla::load(const QByteArray &array)
{
    SendScintilla(SCI_SETTEXT, array.constData());
    SendScintilla(SCI_EMPTYUNDOBUFFER);
}
