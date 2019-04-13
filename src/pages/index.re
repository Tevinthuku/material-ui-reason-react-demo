/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

[@bs.deriving abstract]
type jsProps = {greeting: string};

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <Materialui.Button
        variant=`Contained onClick={_event => self.send(Click)}>
        {ReasonReact.string(message)}
      </Materialui.Button>
      <br />
      <br />
      <Materialui.Button
        variant=`Outlined onClick={_event => self.send(Toggle)}>
        {ReasonReact.string("Toggle Message")}
      </Materialui.Button>
      {self.state.show
         ? <Materialui.Typography variant=`h3>
             {ReasonReact.string(greeting)}
           </Materialui.Typography>
         : ReasonReact.null}
    </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~greeting=jsProps->greetingGet, [||])
  );