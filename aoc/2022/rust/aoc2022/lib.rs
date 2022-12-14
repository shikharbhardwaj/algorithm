/// Runs the file with the correct compiler version, note `#[track_caller]`
#[track_caller]
pub fn example(input: &str, expected_output: &str) {
    let file = Location::caller().file();

    let status = std::process::Command::new("rustc")
        .args(&["+1.53", "-C", "opt-level=3", "-o", "./target/main"])
        .arg(file)
        .status()
        .unwrap();
    assert!(status.success());

    let t = std::time::Instant::now();
    let mut proc = std::process::Command::new("./target/main")
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .spawn()
        .unwrap();
    proc.stdin.take().unwrap().write_all(input.as_bytes()).unwrap();
    let output = proc.wait_with_output().unwrap();
    assert!(output.status.success());
    let stdout = String::from_utf8(output.stdout).unwrap();
    assert_eq!(expected_output, stdout.as_str());
    let file = std::env::current_dir().unwrap().join(file).canonicalize().unwrap();
    let name = file.file_stem().unwrap().to_str().unwrap().replace('_', " ");
    eprintln!("{} ok {:?}:\n    {}", name, t.elapsed(), file.display());
}