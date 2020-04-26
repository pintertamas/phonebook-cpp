#include <iostream>

#include "menu.hpp"

int main() {
    Phonebook phonebook;
    Menu *menu = new Menu(phonebook);
    /*String txt = String("a");
    Work *work = new Work(txt, txt, txt, txt, txt);
    phonebook.addContact(work);

    Private *priv = new Private(txt, txt, txt, txt, txt, 12345678);
    phonebook.addContact(priv);

    //Private *priv2 = new Private(txt, txt, txt, txt, txt, 12345678);
    //phonebook.addContact(priv2);
    phonebook.listContacts(std::cout);*/
    menu->run(phonebook);
    return 0;
}