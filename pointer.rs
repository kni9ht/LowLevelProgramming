struct MyClass {
    // ...
}

impl MyClass {
    fn new() -> MyClass {
        println!("MyClass created");
        MyClass {}
    }

    fn print_hello(&self) {
        println!("Hello");
    }
}

impl Drop for MyClass {
    fn drop(&mut self) {
        println!("MyClass destroyed");
    }
}

fn main() {
    let ptr = MyClass::new();
    ptr.print_hello();
    drop(ptr);
}