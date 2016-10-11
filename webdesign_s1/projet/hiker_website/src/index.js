import React from 'react';
import ReactDOM from 'react-dom';
import {browserHistory, Router, Route} from 'react-router';
import './index.css';

var firebase  = require('firebase');

// Firebase config.
var config = {
    apiKey: "tu vas pas prendre mon apiKey quand meme",
    authDomain: "ok ?",
    databaseURL: "ouais",
    storageBucket: "je prefere",
    messagingSenderId: "salut"
  };
firebase.initializeApp(config);

import Home  from './views/home';
import Admin from './views/admin';
import Travel from './views/travel';
import TravelPage from './views/travelPage';

ReactDOM.render(
        <Router history={browserHistory}>
            <Route path="/" component={Home} firebase={firebase.database()}/>
            <Route path="admin" component={Admin} firebase={firebase} database={firebase.database()}/>
            <Route path="travels" component={Travel} firebase={firebase} database={firebase.database()}/>
                <Route path="travel/:travelId" component={TravelPage} firebase={firebase} database={firebase.database()}/>

        </Router>,
        document.getElementById('root')
);
