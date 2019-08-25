#ifndef ROLODEXENTRY_H_INCLUDED
#define ROLODEXENTRY_H_INCLUDED

#include <string>

class RolodexEntry
{
private:
    std::string fName, lName, street, town, state;
    long zip;
    short szip, area, exchange, line;
    std::string email;
public:
    RolodexEntry(void):fName(), lName(), street(), town(),
    state(), zip(000000000), szip(00000),
    area(0), exchange(0), line(0), email() {}
    RolodexEntry(std::string fname, std::string lname):street(), town(),
    state(""), zip(000000000),
    szip(00000), area(0),
    exchange(0), line(0), email() {}
    RolodexEntry(const RolodexEntry & r):fName(r.fName), lName(r.lName),
    street(r.street), town(r.town),
    state(r.state), zip(r.zip), szip(r.szip),
    area(r.area), exchange(r.exchange),
    line(r.line), email(r.email) {}
    
    std::string getFName() const {return fName;}
    void setFName(std::string first){fName = first;}
    std::string getLName() const {return lName;}
    void setLName(std::string last){lName = last;}
    std::string getStreet() const{return street;}
    void setStreet(std::string str){street = str;}
    std::string getTown() const {return town;}
    void setTown(std::string newtown){town = newtown;}
    std::string getState() const {return state;}
    void setState(std::string newstate){state = newstate;}
    long getZip() const {return zip;}
    void setZip(long newzip){zip = newzip;}
    short getSZip() const {return szip;}
    void setSZipLong(){szip = zip / 10000;}
    void setSZip(short newszip){szip = newszip;}
    short getArea() const {return area;}
    void setArea(short newarea){area = newarea;}
    short getExchange() const {return exchange;}
    void setExchange(short exch){exchange = exch;}
    short getPLine() const {return line;}
    void setPLine(short newline){line = newline;}
    std::string getEmail(){return email;}
    void setEmail(std::string Email){email = Email;}
    
    void printEntry();//other fns
    void readIn();
    bool isEqual(RolodexEntry e){return e.fName == fName && e.lName == lName &&
        e.street == street && e.town == town &&
        e.state == state && e.zip == zip && e.szip == szip &&
        e.area == area && e.exchange == exchange && e.line == line &&
        e.email == email;}
};

#endif // ROLODEXENTRY_H_INCLUDED

