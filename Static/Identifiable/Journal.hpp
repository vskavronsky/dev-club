#ifndef JOURNAL_H
#define JOURNAL_H

#include "Identifiable.hpp"

class Journal : public Identifiable {
    private:
        std::string m_title;
        double m_price;

    public:
        Journal(const std::string& title, double price);
        Journal(const Journal& copy);
        virtual ~Journal();

        const std::string& getTitle() const;
        double getPrice() const;

        void setTitle(const std::string& title);
        void setPrice(double price);

        Journal& operator=(const Journal& copy);

};

std::ostream& operator<<(std::ostream& out, const Journal& journal);

#endif // JOURNAL_H
