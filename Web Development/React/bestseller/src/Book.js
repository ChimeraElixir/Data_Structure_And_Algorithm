import React from "react"
import "./Book.css"

const Book = (props) => {
  return (
    <div className="book">
      <div className="book-img">
        <img src={props.imageLink} alt="" />
      </div>
      <div className="book-info">
        <h1 className="book-title">{props.title}</h1>
        <p className="book-author"> {props.author}</p>
        <p className="book-price">{props.price}</p>
        <button className="book-button">Add To Cart</button>
      </div>
    </div>
  )
}

export default Book
