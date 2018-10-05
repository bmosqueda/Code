import React from 'react';
import ReactDOM, { render } from 'react-dom';
import './index.css';
import * as serviceWorker from './serviceWorker';

import { BrowserRouter as Router } from 'react-router-dom';

// Routes
import AppRoutes from './routes';

const root = document.getElementById('root');

ReactDOM.render(
  <Router>
    <AppRoutes />
  </Router>
  , 
  root
);

serviceWorker.unregister();