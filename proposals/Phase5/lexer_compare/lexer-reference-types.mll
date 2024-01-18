rule token = parse
  | "extern" { EXTERN }
  | "externref" { EXTERNREF }

  | "ref.null" { REF_NULL }
  | "ref.func" { REF_FUNC }
  | "ref.extern" { REF_EXTERN }
  | "ref.is_null" { REF_IS_NULL }

  | "table.get" { TABLE_GET }
  | "table.set" { TABLE_SET }
  | "table.size" { TABLE_SIZE }
  | "table.grow" { TABLE_GROW }
  | "table.fill" { TABLE_FILL }
  | "table.copy" { TABLE_COPY }
  | "table.init" { TABLE_INIT }
  | "elem.drop" { ELEM_DROP }


  | "memory.fill" { MEMORY_FILL }
  | "memory.copy" { MEMORY_COPY }
  | "memory.init" { MEMORY_INIT }
  | "data.drop" { DATA_DROP }


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