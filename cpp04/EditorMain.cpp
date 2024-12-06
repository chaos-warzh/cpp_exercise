//
// Created by DELL on 2024/12/6.
//
#include "TextEditor.h"

void TEST_0() {
    TextEditor editor;
    editor.addText("word");
    editor.moveCursor(-1);
    editor.addText("l");
    editor.moveCursor(-4);
    editor.addText("hello ");
    editor.print();
    editor.moveCursor(5);
    editor.deleteText(5);
    editor.addText("cpp");
    editor.print();
}
// hello world
// hello cpp

void TEST_1() {
    TextEditor editor;
    editor.addText("njuverygood");
    editor.copy(8);
    for (int i = 0; i < 5; i++) {
        editor.paste();
    }
    editor.print();
}
// njuverygoodverygoodverygoodverygoodverygoodverygood

void TEST_2() {
    TextEditor editor;
    editor.addText("hello");
    editor.moveCursor(-100);
    editor.copy(100);
    editor.moveCursor(100);
    editor.deleteText(100);
    editor.paste();
    editor.print();
}
// 输出为空行

int main() {
    TEST_0();
    TEST_1();
    TEST_2();

    return 0;
}