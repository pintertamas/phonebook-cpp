#include <iostream>

#include "menu.hpp"

int main() {
    auto *phonebook = new Phonebook();
    Menu *menu = new Menu(*phonebook);
    String txt = String("a");
    auto *work = new Work(txt, txt, txt, txt, txt);
    auto *priv = new Private(txt, txt, txt, txt, txt, 12345678);
    phonebook->addContact(work);
    phonebook->addContact(priv);
    std::cout<<phonebook->getWorkContacts(0) << std::endl;
    std::cout<<phonebook->getPrivateContacts(2) << std::endl;
    phonebook->listContacts(std::cout);
    //menu->run();
    return 0;
}