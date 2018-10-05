import React from 'react';
import { Route, Switch } from 'react-router-dom';

import App from '@app';
import Home from '@app/Home/Home';
import About from '@app/About/About';
import Contact from '@app/Contact/Contact';
import Error404 from '@app/Error404/Error404';

const AppRoutes = () => (
  <App>
    <Switch>
      <Route path="/home" component={Home} exact />
      <Route path="/about" component={About} exact />
      <Route path="/contact" component={Contact} exact />
      <Route component={Error404} />
    </Switch>
  </App>
);

export default AppRoutes;