import React, { Component } from 'react';
import './App.css';
import Header from './shared/components/Header';
import Content from './shared/components/Content';
import Footer from './shared/components/Footer';
// import Calculator from './components/Calculator';

class App extends Component {
  render() {
    const { children } = this.props;
    return (
      <div className="App">
        <Header />

        <Content>
          { children }
        </Content>

        <Footer copyright="&copy 2018"/>
      </div>
    );
  }
}

export default App;