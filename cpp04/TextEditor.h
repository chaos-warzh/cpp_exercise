//
// Created by DELL on 2024/12/6.
//

#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <list>
#include <string>

class TextEditor {
public:
    TextEditor();

    void addText(const std::string& text);

    void deleteText(int length);

    void moveCursor(int steps);

    void copy(int length) const;

    void paste();

    void print() const;

private:
    std::list<char> text_list;

    std::list<char>::iterator cursor;
};

#endif //TEXTEDITOR_H
