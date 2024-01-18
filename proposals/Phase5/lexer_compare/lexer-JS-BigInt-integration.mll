rule token = parse


  | (ixx as t)".extend8_s" { UNARY (intop t i32_extend8_s i64_extend8_s) }
  | (ixx as t)".extend16_s" { UNARY (intop t i32_extend16_s i64_extend16_s) }
  | "i64.extend32_s" { UNARY i64_extend32_s }

  | (ixx as t)".trunc_sat_f32_s"
    { CONVERT (intop t i32_trunc_sat_f32_s i64_trunc_sat_f32_s) }
  | (ixx as t)".trunc_sat_f32_u"
    { CONVERT (intop t i32_trunc_sat_f32_u i64_trunc_sat_f32_u) }
  | (ixx as t)".trunc_sat_f64_s"
    { CONVERT (intop t i32_trunc_sat_f64_s i64_trunc_sat_f64_s) }
  | (ixx as t)".trunc_sat_f64_u"
    { CONVERT (intop t i32_trunc_sat_f64_u i64_trunc_sat_f64_u) }