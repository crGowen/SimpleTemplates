// shorthand js function declarations

export function $h() {return document.head;};
export function $b() {return document.body;};

export function $new(type) {return document.createElement(type);};
export function $new_id(type, name) {var c = document.createElement(type); c.id = name; return c;};

export function $id(name) {return document.getElementById(name);};
export function $class(clname) {return document.getElementsByClassName(clname);};

export function $del(elem) {if (elem) elem.parentNode.removeChild(elem);};

export function $empty(elem) {while (elem.childNodes.length > 0) { elem.removeChild(elem.childNodes[0]);} }; 
