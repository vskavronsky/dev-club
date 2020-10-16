#include <iostream>
#include "Customer.h"
#include "Order.h"
#include "Item.h"
#include "Category.h"

int main() {
    try {
        Category* phones = new Category("Phones");
        Item* iphone = new Item("Iphone", 399, phones);
        Item* samsung = new Item("Samsung", 295, phones);

        Category* fruits = new Category("Fruits");
        Item* apple = new Item("Apple", 4.99, fruits);
        Item* banana = new Item("Banana", 6.99, fruits);

        Customer* mike = new Customer("Mike", 700);
        Customer* bob = new Customer("Bob", 500);

        Order* order = new Order(mike, iphone);
        order->addItem(apple);

        Order* order2 = new Order(bob, samsung);
        order2->addItem(banana);

        Category::getCategoryList();
        std::cout << "phones - " << phones->getUniqueId() << std::endl;
        std::cout << "fruits - " << fruits->getUniqueId() << std::endl << std::endl;;

        Item::getItemList();
        std::cout << "iphone - " << iphone->getUniqueId() << std::endl;
        std::cout << "samsung - " << samsung->getUniqueId() << std::endl;
        std::cout << "apple - " << apple->getUniqueId() << std::endl;
        std::cout << "banana - " << banana->getUniqueId() << std::endl << std::endl;;

        Customer::getCustomerList();
        std::cout << "mike - " << mike->getUniqueId() << std::endl;
        std::cout << "bob - " << bob->getUniqueId() << std::endl << std::endl;

        Order::getOrderList();
        std::cout << "order - " << order->getUniqueId() << std::endl;
        std::cout << "order2 - " << order2->getUniqueId() << std::endl << std::endl;

        delete bob;
        bob = nullptr;

        delete mike;
        mike = nullptr;

        delete fruits;
        fruits = nullptr;

        delete phones;
        phones = nullptr;

    } catch ( const InvalidParameterMoney& ex ) {
        std::cout << ex.what() << std::endl;
    } catch ( const InvalidParameterPrice& ex ) {
        std::cout << ex.what() << std::endl;
    } catch ( const OutOfMoney& ex ) {
        std::cout << ex.what() << std::endl;
    } catch ( const NotEnoughMoney& ex ) {
        std::cout << ex.what() << std::endl;
    } catch ( const CategoryWithoutItems& ex ) {
        std::cout << ex.what() << std::endl;
    } catch ( const CustomerWithoutOrders& ex ) {
        std::cout << ex.what() << std::endl;
    } catch ( const ItemWithoutOrders& ex ) {
        std::cout << ex.what() << std::endl;
    } catch ( const OrderWitoutItems& ex ) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
