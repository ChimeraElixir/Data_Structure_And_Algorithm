import Book from "./Book"
import React from "react"
import books from "./books.json"

const BookList = () => {
  return (
    <div>
      {books.map((ele) => {
        return (
          <Book
            imageLink={ele.imageLink}
            title={ele.title}
            author={ele.author}
            price={ele.price}
          />
        )
      })}
    </div>
  )
}

export default BookList
