import AppKit
import Foundation

guard CommandLine.arguments.count == 2,
      let imageData = try? Data(contentsOf: URL(fileURLWithPath: CommandLine.arguments[1])),
      let bitmap = NSBitmapImageRep(data: imageData),
      bitmap.pixelsWide > 0, bitmap.pixelsHigh > 0 else {
    fputs("screen_capture_unreadable\n", stderr)
    exit(2)
}

// Ignore the status bar and edges. A black AGR root with white system chrome
// must not be classified as a visible game frame.
let x0 = bitmap.pixelsWide / 5
let x1 = bitmap.pixelsWide * 4 / 5
let y0 = bitmap.pixelsHigh / 5
let y1 = bitmap.pixelsHigh * 4 / 5
let stepX = max(1, (x1 - x0) / 64)
let stepY = max(1, (y1 - y0) / 64)
var sampled = 0
var nonblack = 0
for y in stride(from: y0, to: y1, by: stepY) {
    for x in stride(from: x0, to: x1, by: stepX) {
        sampled += 1
        if let color = bitmap.colorAt(x: x, y: y)?.usingColorSpace(NSColorSpace.deviceRGB),
           max(color.redComponent, max(color.greenComponent, color.blueComponent)) > 0.08 {
            nonblack += 1
        }
    }
}
print("simulator_screen sampled=\(sampled) nonblack=\(nonblack)")
if nonblack < 20 { exit(1) }
