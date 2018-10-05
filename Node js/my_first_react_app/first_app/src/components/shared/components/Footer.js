import React from 'react';
import PropTypes from 'prop-types';

const Footer = (props) => <h1>{ props.copyright }</h1>;

//Se definen los props que se van a recibir
Footer.propTypes = {
  copyright: PropTypes.string.isRequired
};

export default Footer;