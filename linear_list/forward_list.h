//
// Created by Anis Han on 2024/1/25.
//

#ifndef CPPPROJECT01_FORWARD_LIST_H
#define CPPPROJECT01_FORWARD_LIST_H

#include <linear_list.h>
#include <stdexcept>

template <typename T>
class ForwardList : public LinearList<T> {

    class Node {
    public:
        T element;
        Node *next;
        explicit Node(): next{nullptr} {}
        explicit Node(T e): element{e}, next{nullptr} {}
    };

    Node *head_;

public:
    ForwardList() {
        head_ = new Node();
    }

    auto clear() -> void override {
        Node *temp;
        Node *current = head_->next;
        while (current) {
            temp = current->next;
            delete current;
            current = temp;
        }
        head_->next = nullptr;

    }

    auto isEmpty() -> bool override {
        return head_->next == nullptr;
    }

    auto length() -> int override {
        int size = 0;
        Node *current = head_;
        while (current->next) {
            current = current->next;
            ++size;
        }
        return size;
    }

    auto get(int i) -> T override {

        Node *current = head_;
        while (current->next && i >= 0) {
            current = current->next;
            i--;
        }

        if (current == nullptr) throw std::out_of_range("out of range");
        return current->element;
    }

    auto insert(int i, T t) -> void override {
        Node *prev = nullptr;
        Node *current = head_;
        while (current && i >= 0) {
            prev = current;
            current = current->next;
            i--;
        }
//        if (current == nullptr && i == 0) {
//            prev->next = new Node();
//        }
        if (i == -1 && current == nullptr) {
            prev->next = new Node(t);
            return;
        } else {
            if (current == nullptr) throw std::out_of_range("out of range");
        }
        prev->next = new Node(t);
        prev->next->next = current;

    }

    auto insert(T t) -> void override {
        Node *current = head_;
        while (current->next) {
            current = current->next;
        }

        current->next = new Node(t);
    }

    auto remove(int i) -> T override {
        Node *prev = nullptr;
        Node *current = head_;
        while (current && i >= 0) {
            prev = current;
            current = current->next;
            i--;
        }

        if (current == nullptr) throw std::out_of_range("out of range");

        prev->next = current->next;
        T temp = current->element;
        delete current;
        return temp;
    }

    auto find(T t) -> int override {
        int index = -1;
        Node *current = head_;
        while (current->next) {
            current = current->next;
            ++index;
            if (current->element == t) {
                return index;
            }
        }
        return -1;
    }

    ~ForwardList() {
        clear();
        delete head_;
    }

};

#endif //CPPPROJECT01_FORWARD_LIST_H
