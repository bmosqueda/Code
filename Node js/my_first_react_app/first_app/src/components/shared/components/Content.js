import React from 'react';
import { element } from 'prop-types';

const Content = (props) => {
  const { children } = props;
  return (
    <div className="Content">
      {children}
    </div>
  );
}

Content.propTypes = {
  children: element
}

export default Content;