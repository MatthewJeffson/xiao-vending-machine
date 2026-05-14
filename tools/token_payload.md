# Token payload

Starter token format:

```text
TRUE
```

Recommended production format:

```json
{
  "paid": true,
  "sku": "XIAO-RP2040",
  "qty": 1,
  "txn": "2026-05-14-0001"
}
```

For a minimal RFID card demo, write `TRUE` to the agreed card block and have the Wio Terminal check the first four bytes.
