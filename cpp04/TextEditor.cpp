//
// Created by DELL on 2024/12/6.
//
#include "TextEditor.h"

#include <iostream>

using namespace std;


TextEditor::TextEditor() {
    // TODO: 用空文本初始化
    text_list.clear();
    cursor = text_list.begin();
    buf = "";
}

void TextEditor::addText(const string& text) {
    // TODO: 将 text 添加到光标所在位置
    for (auto it : text) {
        text_list.insert(cursor, it);
    }
}

void TextEditor::deleteText(int length) {
    // TODO: 删除光标左边 length 个字符
    auto first = cursor;
    for (int i = 0 ; i < length; i++) {
        if (first == text_list.begin()) {
            break;
        }
        --first;
    }
    cursor = text_list.erase(first, cursor);
}

void TextEditor::moveCursor(int steps) {
    // TODO: 将光标向左向右移动
    bool to_left = false;
    if (steps < 0) {
        to_left = true;
        steps = -steps;
    }
    for (int i = 0 ; i < steps; i++) {
        if (to_left) {
            if (cursor == text_list.begin()) {
                break;
            }
            --cursor;
        } else {
            if (cursor == text_list.end()) {
                break;
            }
            ++cursor;
        }
    }
}

void TextEditor::copy(int length) {
    // TODO: 复制光标左侧 length 个字符
    auto iter = cursor;
    buf.clear();
    if (iter== text_list.begin()) {
        return;
    }
    --iter;
    for (int i = 0; i < length; i++, --iter) {
        buf += *iter;
        if (iter == text_list.begin()) {
            return;
        }
    }
}

void TextEditor::paste() {
    // TODO: 在光标处添加上一次复制的文本
    const unsigned long long len = buf.length();
    for (int i = 0 ; i < len; i++) {
        text_list.insert(cursor, buf[len - 1 - i]);
    }
}

void TextEditor::print() const {
    // TODO: 输出当前编辑器内容
    for (auto c : text_list) {
        cout << c;
    }
    cout << endl;
}
