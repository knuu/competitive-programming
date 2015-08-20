let rec hello_world n =
  match n with
    0 -> ()
  | n' -> (print_string "Hello World\n";
	   hello_world (n-1))
;;  

let () =
  let n  = read_int() in
  hello_world n
;;
  
