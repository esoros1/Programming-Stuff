 /*  Eric Soros
   *  CS 33001
  *  April 17, 2011
  *  Prog 4, Part 1
  */ 

#include "sexpr.h"
#include <cassert>
///////////////////////////////////////////////////
//
// File:        sexpr.cpp
//              Program 4 CS II
// Programmer:   
// Date:        04/11/2011
//
// Description: Implementation of a class for a Lisp S-expression.
//              Used in conjunction with class lispnode.
//
//              Destructor (garbage collection) must be explicitly
//              called.



//////////////////////////////////////////////////////////
// A destructor (for lispnode) to be called explicitly.
//
// PRE:  Assigned(ptr)
// POST: All memory ptr points to is deleted.
//
void garbageCollect(lispnodeptr &ptr) {   
    //while there is still stuff to delete
    while(ptr) {
   		lispnodeptr temp = ptr;
   		ptr = ptr -> next;
   			//if it's an atom, than we can just delete the lispnode
   			if(temp->identity == anAtom)
   				delete temp;
   		//else it's a list
   			else {
   				//recursively delete the sublist, than delete the node
   				garbageCollect(temp->sublist);
   				delete temp;
   			}
   	}

}


//////////////////////////////////////////////////////////
// Free function for reading in an Atom.
// PRE:  (ch == first character of atom)
// POST: (RETVAL == atom) && (ch == next character from input)
string getAtom(/*IN/OUT*/ std::istream& in, 
               /*IN/OUT*/ char &ch) {
    string result;
    result = ch;
    in.get(ch);
    while ((ch != ' ') && (ch != ')') && (ch != '(') && (ch != '\n')) {
        result = result + ch;
        in.get(ch);
    }
    return result;
}

////////////////////////////////////////////////////////// 
// Free function to convert int to string.
// PRE:  assigned(n).
// POST: Return a text version of integer.
// //itoa(n, result.str, 10); -- not working on g++
string int_to_string(int n) {
    string result, sign;
    
    if (n == 0) return string("0");
    if (n < 0) { 
        sign = "-"; 
        n = -n;  
    }
    while (n > 0) {
        result = char(int('0') + (n%10)) + result;
        n = n / 10;
    }  
    return sign + result;
}



//////////////////////////////////////////////////////////
// Input a S-expression
// PRE:  s should not be pointing to anything.
// POST: s->lisp expression.
std::istream& operator>>(std::istream& in, lispnodeptr& s) {
    char        ch;
    bool        endOfExpression = false;
    lispnode    *temp = 0,
                *ptr = 0;

    in >> ch;
    while (!endOfExpression)
        switch(ch) {
        case ' ':  //Skip blanks.
            in >> ch;
            break;

        case '(':  //New list.
            temp = new lispnode(aList);
            in >> temp->sublist;
            if (s == 0)  s = temp;
            else ptr->next = temp;
            ptr = temp;
            in >> ch;
            break;

        case ')':  //End of a list.
            endOfExpression = true;
            break;

        default:   //An atom.
            temp = new lispnode(anAtom);
            temp->sym = getAtom(in, ch);  //Returns ch!
            if (s == 0) s = temp;
            else ptr->next = temp;
            ptr = temp;
       }
    return in;
}

//////////////////////////////////////////////////////////
// PRE:  Assigned(s)
// POST: Lisp expression is printed.
std::ostream& operator<<(std::ostream& out, const lispnodeptr s) {
    lispnodeptr temp = s;
    bool onlyOne = true;

    while (temp != 0) {
        switch (temp->identity)
        {
        case anAtom:
            if (onlyOne) out << temp->sym;
            else out << " " << temp->sym;
            onlyOne = false;
            break;
        case aList:
            if (onlyOne) out << "(";
            else out << " (";
            out << temp->sublist;
            onlyOne = false;
            out << ")";
            break;
        }
        temp = temp->next;
    }
    return out;
}



//////////////////////////////////////////////////////////
// Constructor - numeric atom
//
sexpr::sexpr(const int val) {  
    identity = anAtom;
    symbol = int_to_string(val);
    lst      = 0;
}




//////////////////////////////////////////////////////////
// A destructor to be called explicitly.
//
void sexpr::garbageCollection() {
    garbageCollect(lst);
    identity = aList;
    symbol   = "";
    lst      = 0;
}


//////////////////////////////////////////////////////////
//Evaluate a Lisp S-expression.
//
//PRE:  s.identity == aList
//POST: returns an sexpr
sexpr eval(const sexpr& s) {
    
    //*************NEED TO IMPLEMENT***********************

    //assert(s.identity == aList);  
    if (s.lst == 0) return sexpr();
    //if it is bye, than exit
    if (s.lst->sym == "bye") return sexpr("bye");
    //if quote, than return the rest of the list
    if (s.lst->sym == "quote") {
       //if the next thing is a list, than we can use the sexpr constructor
       //that takes a lispnode!
       if(s.lst->next->identity == aList) 
			return(s.lst->next->sublist);
		//else, it is a single atom, and we can make an sexpr that takes 
		//the same symbol as the atom
		else 
			return (sexpr(s.lst->next->sym));
    } else {
        //the first item is a function
        string func = s.lst->sym;
		if (func == "rest") 
			return rest(eval(s.lst->next->sublist));
		else if (func == "first")
			return first(eval(s.lst->next->sublist));
		else if (func == "copy")
			return copy(eval(s.lst->next->sublist));
		else if (func == "length")
			return length(eval(s.lst->next->sublist));
		else if (func == "list")
			return list(eval(s.lst->next->sublist),(eval(s.lst->next->next->sublist)));
		else if (func == "cons")
			return cons(eval(s.lst->next->sublist),(eval(s.lst->next->next->sublist)));
		else if (func == "append")
			return append(eval(s.lst->next->sublist),(eval(s.lst->next->next->sublist)));
		else if (func == "reverse")
			return reverse(eval(s.lst->next->sublist));
		else
			return sexpr();
    }
    
}

//////////////////////////////////////////////////////////
// PRE:  s.identity == aList
// POST: (first (quote (a b c))) == a
// if blank sexpr, return sexpr()
sexpr first(const sexpr& s) {
    //*************NEED TO IMPLEMENT***********************
	//if the first things is an atom, reurn a new atom with the 
	//same sym.
	if (s == sexpr()) return sexpr();
	if (s.lst->identity== anAtom)
		return sexpr(s.lst->sym);
	//else it's a list, 
	else
		return sexpr(s.lst->sublist);
}

//////////////////////////////////////////////////////////
// PRE:  s.identity == aList
// POST: (rest (quote (a b c))) == (b c)
sexpr rest(const sexpr& s) {
    //*************NEED TO IMPLEMENT***********************
     return sexpr(s.lst->next);
}


//////////////////////////////////////////////////////////
// PRE:  s.identity == aList
// POST: (length (quote (a b (c d)))) == 3
sexpr length(const sexpr& s) {
    //*************NEED TO IMPLEMENT***********************
    lispnodeptr temp = s.lst;
    int count = 0;
    //if temp is not zero, loop through couting how many are in 
    //the top level
    if (temp)
    {
		while(temp != 0)
		{
			++count;
			temp = temp->next;
		}
	}
	return sexpr(count);
}

//////////////////////////////////////////////////////////
// PRE:  none
// POST: (list (quote a) (quote (b c)) ) == (a (b c))
sexpr list(const sexpr& a, const sexpr& b) {
    //*************NEED TO IMPLEMENT***********************
   
    lispnodeptr result;
    //if a is an atom, make a new lispnodeptr for an atom   
    if(a.identity == anAtom ) {
		result = new lispnode(anAtom);
		result->sym = a.symbol;
	}
	//if a is a list, make a new list
	if(a.identity == aList) {
		result = new lispnode(aList);
		result->sublist = a.lst;
	}
     //if b is an atom, make a new lispnodeptr for an atom   
    if(b.identity == anAtom ) {
		result->next = new lispnode(anAtom);
		result->next->sym = b.symbol;
	}
   	//if b is a list, make a new list
	if(b.identity == aList) {
		result->next = new lispnode(aList);
		result->next->sublist = b.lst;
	}
   return result;
}

//////////////////////////////////////////////////////////
// PRE:  b.identity == aList
// POST: (cons (quote a) (quote (b c)) ) == (a b c)
sexpr cons(const sexpr& a, const sexpr& b) {
    //*************NEED TO IMPLEMENT***************e********
    //if a is an atom, than we make a new lispnodeptr, and set the next
    //to be b.lst
	lispnodeptr result;
	if (a.identity == anAtom) {
		result = new lispnode(anAtom);
		result->sym = a.symbol;
	}
	//if a is a list, do the same thing, but with a list
	if (a.identity == aList) {
		result = new lispnode(aList);
		result->sublist = a.lst;
	}
	//set result->next to be the b.lst
	result-> next = b.lst;
	return result;
}

////////////////////////////////////////////////////////////
// PRE: a.identiy == aList && b.identity == aList
// POST: (append (quote (a)) (quote(b c))) == (a b c)
sexpr append (const sexpr& a, const sexpr& b) {
	
	//set result equal to the first list.
	lispnodeptr result = a.lst;
	//traverse the list until the end
	lispnodeptr temp = result;
	if(temp) {
		while(temp ->next != 0)
			temp = temp->next;
	}
	//tack on the list from b
	temp->next = b.lst;
	return result;
}
///////////////////////////////////////////////////////////
//PRE: s.identity == aList
//POST: the reversed list is returned
sexpr reverse(const sexpr& s) {
	//if it has one element, the list is reversed
	lispnodeptr head = s.lst;
	if(head->next == 0)
		return head;
	
	//recursively call reverse, set temp equal to it 
	lispnodeptr tail = reverse(head->next).lst;
	
	//append head to the tail of the recursively reversed list
	lispnodeptr temp = tail;
	while (temp->next != 0)
		temp = temp->next;
	
	temp->next = head;
	//set head to zero, which ends the list
	head->next = 0;
	return tail;
}

//////////////////////////////////////////////////////////
//PRE: S is a valid s-expression
//POST: A copy of s is returned;
sexpr copy(const sexpr& s) {
	//if s is an atom, just return a new sexpr with the same symbol
	if (s.identity == anAtom)
		return sexpr(s.symbol);
	
	//else it's a list, and we have to copy the atoms one by one
	lispnodeptr ptr = s.lst;
	lispnodeptr temp;
	//find out what ptr is so we can have the first pointer correct
	if(ptr->identity == anAtom)
		temp = new lispnode(anAtom);
	else
		temp = new lispnode(aList);
	//temp gets moved around, so result is a pointer to the front of the list
	lispnodeptr result = temp;
	while(ptr) {
		//if ptr is a list, than recursively copy that list.
		if(ptr->identity == aList) 
			temp->sublist = copy(ptr->sublist).lst;
		//else it's an atom, and we can just copy the symbol
		else 
			temp->sym = ptr->sym;
		//increment ptr, and if it has another atom, than continue the list
		ptr = ptr -> next;
		if (ptr) {
			if (ptr->identity == anAtom)
				temp->next = new lispnode(anAtom);
			else temp->next = new lispnode(aList);
			temp = temp->next;
		}
	}
	return result;
}


//////////////////////////////////////////////////////////
// Are two sexpr equal at TOP level? (eq)
// 
bool sexpr::operator== (const sexpr& s)  const {
    if ((identity == s.identity) &&
        (lst == s.lst) &&
        (symbol == s.symbol))
        return true;
    else
        return false;
}


//////////////////////////////////////////////////////////
// Input. (read)
// PRE:  none
// POST: A S-expression is read in. 
std::istream& operator>>(std::istream& in, sexpr& s) {
    char        ch;

    in >> ch;
    switch(ch) {
    case '(':  //New list.
        s.identity  = aList;
        in >> s.lst;
        break;
    default:   //An atom.
        s.identity  = anAtom;
        s.symbol    = getAtom(in, ch);
    }
    return in;
}


//////////////////////////////////////////////////////////
// Output (print)
// PRE:  Assigned (s)
// POST: The S-expression is printed out.
std::ostream& operator<<(std::ostream& out, const sexpr& s) {
    if (s.identity == anAtom)
        out << s.symbol;
    else   
       out << "(" << s.lst << ")";
    return out;
}
//PRE: in is a valid file containg sexpr's.
//POST: the next sexpr is returned.
sexpr getNextSexpr(std::istream& in)
{
	sexpr result;
	in >> result;
	return result;
}

///////////////////////////////////////////////////////////////
//Used for testing
//PRE: ptr-> next != 0
//POST: ptr->next is returned
lispnodeptr getNextAtom(lispnodeptr ptr) {
	return ptr->next;
}
