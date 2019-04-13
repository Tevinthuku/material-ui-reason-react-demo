import React, { Component } from 'react';
import Indexpage from "./pages/index.bs.js"

class App extends Component {
  render() {
    return (
      <div>
        <Indexpage greeting="Hi there @material-ui User" />
      </div>
    );
  }
}

export default App;
