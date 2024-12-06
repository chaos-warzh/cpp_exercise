//
// Created by DELL on 2024/12/6.
//
#include "TextEditor.h"

using namespace std;

TextEditor::TextEditor() {
    // TODO: 用空文本初始化
    text = new list<char>();
    cursor = text->begin();
};


TextEditor::~TextEditor() {
    // TODO: 用空文本初始化
    delete text;
};


void TextEditor::addText(const string& text) {
    // TODO: 将 text 添加到光标所在位置
    for (int i = 0 ; i < text.length(); i++) {
        if (cursor < text.length()) {

        }
    }
}

void TextEditor::deleteText(int length) {
    // TODO: 删除光标左边 length 个字符
}

void TextEditor::moveCursor(int steps) {
    // TODO: 将光标向左向右移动
}

void TextEditor::copy(int length) {
    // TODO: 复制光标左侧 length 个字符
}

void TextEditor::paste() {
    // TODO: 在光标处添加上一次复制的文本
}

void TextEditor::print() {
    // TODO: 输出当前编辑器内容
}