class Library():
    def __init__(self):
        self.__books = []

    def add_book(self, book):
        self.__books.append(book)

    def remove_book(self, isbn):
        for book in self.__books:
            if (isbn == book.get_isbn()):
                self.__books.remove(book)
                return
        print("No book found with that isbn") 

    def borrow_book(self, isbn):
        for book in self.__books:
            if (isbn == book.get_isbn()):
                book.borrow_book()
                return
        print("No book found with that isbn") 
    
    def return_book(self, isbn):
        for book in self.__books:
            if (isbn == book.get_isbn()):
                book.return_book()
                return
        print("No book found with that isbn") 

    def list_avalible_books(self):
        for book in self.__books:
            if book.avalible == True:
                print(book)