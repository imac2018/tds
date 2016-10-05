require('styles/normalize.css');
require('styles/App.scss');

import React from 'react';

class AppComponent extends React.Component {
  render() {
    return (
       <div className="index">
          <h1>Voyage vers la soie</h1>
          <h2>Le blog de Marco Polo</h2>
       </div>
    );
  }
}

AppComponent.defaultProps = {
};

export default AppComponent;
