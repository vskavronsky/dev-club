#ifndef IDENTIFIABLE_HPP
#define IDENTIFIABLE_HPP

#include <iostream>

class Identifiable {
    protected:
        int m_uniqueId;
        static int m_id;

    public:
        Identifiable();
        virtual ~Identifiable();

        int getUniqueId() const;

};

#endif // IDENTIFIABLE_HPP
