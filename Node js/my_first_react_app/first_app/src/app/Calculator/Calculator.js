import React, { Component } from 'react';
import './Calculator.css';

class Calculator extends Component {
  state = {
    name: "Brandon",
    number1: 0,
    number2: 0,
    result: 0
  }

  componentDidMount() {
    this.setState({
      name: "Alejandro"
    });
  }

  // this.handleChange = this.handleChange.bind(this);
  handleChange = (event) => {
    const { target: { name, value } } = event;
    this.setState({
      [name]: Number(value)
    });
  }

  handleClick = () => {
    const result = this.state.number1 + this.state.number2;

    this.setState({
      result
    });
  }

  render() {
    console.log(this.state.name);
    const inputStyle = {fontSize: '20px'};
    return (
      <div className="Calculator">
        <input 
          name="number1" 
          type="number" 
          value={this.state.number1}
          onChange={this.handleChange}
          style={inputStyle}
        />
        { '+' }
        <input 
          name="number2" 
          type="number" 
          value={this.state.number2}
          style={inputStyle}
          onChange={this.handleChange}
        />
        <button onClick={this.handleClick}>=</button>
        <p>
          {this.state.result}
        </p>
      </div>
    );
  }
}

export default Calculator;