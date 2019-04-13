module Button = {
  [@bs.deriving jsConverter]
  type variant = [
    | [@bs.as "text"] `Text
    | [@bs.as "outlined"] `Outlined
    | [@bs.as "contained"] `Contained
    | [@bs.as "fab"] `Fab
    | [@bs.as "extendedFab"] `ExtendedFab
    | [@bs.as "flat"] `Flat
    | [@bs.as "raised"] `Raised
  ];

  [@bs.obj]
  external makeProps:
    (~variant: string=?, ~onClick: ReactEvent.Mouse.t => unit=?, unit) => _ =
    "";

  [@bs.module "@material-ui/core/Button"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~variant: option(variant)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
          ~onClick?,
          (),
        ),
      children,
    );
};

module Typography = {
  [@bs.deriving jsConverter]
  type variant = [
    | [@bs.as "h1"] `h1
    | [@bs.as "h2"] `h2
    | [@bs.as "h3"] `h3
    | [@bs.as "h4"] `h4
    | [@bs.as "h5"] `h5
    | [@bs.as "h6"] `h6
    | [@bs.as "subtitle1"] `subtitle1
    | [@bs.as "subtitle2"] `subtitle2
    | [@bs.as "body1"] `body1
    | [@bs.as "body2"] `body2
  ];

  [@bs.obj] external makeProps: (~variant: string=?, unit) => _ = "";

  [@bs.module "@material-ui/core/Typography"]
  external reactClass: ReasonReact.reactClass = "default";

  let make = (~variant: option(variant)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
          (),
        ),
      children,
    );
};