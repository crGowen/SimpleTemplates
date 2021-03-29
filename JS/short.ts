// shorthand ts function declarations

const short = {
    h: () => { return document.head },

    b: () = > { return document.body },

    create: (type:string, id:string, classes:string[]) => {
        let c = document.createElement(type);

        if (id.length > 0) {
            c.id = id;
        }

        for (let i = 0; i < classes.length; i++) {
            c.classList.add(classes[i]);
        }

        return c;
    },

    byId: (name:string) => {return document.getElementById(name); },

    byClass: (clname:string) => {return document.getElementsByClassName(clname); },

    del: (elem:Element) => {if (elem) elem.parentNode.removeChild(elem); },

    clearChildren: (elem:Element) => {
        while (elem.childNodes.length > 0) {
            elem.removeChild(elem.childNodes[0]);
        }
    },

    checkForMobile: () => {
        var regex = /Mobi|Android/i;

        return regex.test(navigator.userAgent);
    },

    generator: ( appendTo:Element, html:string, args:any) => {
        var htmlRes = ``;
        for (var arg of args) {
            htmlRes = html;
            for (var key in arg) {
                htmlRes = htmlRes.replaceAll(`[>>${key}<<]`, arg[key]);
            }
            appendTo.innerHTML += htmlRes;
        }
    },

    fillWithHtml: async (appendTo:Element, fetchUrl:string) => {

        let response = await fetch(fetchUrl);
        let result = await response.text();
        let parser = new DOMParser();
        let dom = parser.parseFromString(result, "text/html");

        appendTo.innerHTML += dom.getElementsByTagName("body")[0].innerHTML;
    }
}
